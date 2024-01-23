/*
 ============================================================================
 Program Name: Simplified AES Encription/Decryption
 Author      : Ahmed Emad
 Version     : 1.0
 Date        : 11/22/2023
 Description : type paramenters in windows cmd => [Application path] [ENC/DEC for Encryption or Decryption] [data in hex (max 4 digits)] [key in hex (max 4 digit)]
 Example	:>> main.exe ENC 6DF4 42FA
 Notes       : The Parameters is not case sensetive and prints messages when wrong paramenters entered
 ============================================================================
 */
/* Includes */
#include <stdio.h>
#include <string.h>
/************************* Data Types *************************/
typedef unsigned char u8; 
typedef unsigned short int u16; 
typedef int s32;
typedef unsigned int u32;
typedef enum bool{false,true} bool;
typedef enum errorState{OK,NOK} enErrorState;
typedef enum state{ENC,DEC} enState;
/************************* Macros *************************/
/* Print Macros */
#define print(x)                    printf("%d ",x) 
/* Bit Operation Macros */
#define GetByte(data,index)         ((u8)((data>>(index*8))&0xFF)) 
#define GetNibble(data,index)       ((u8)((data>>(index*4))&0x0F)) 
#define GetCrumb(data,index)        ((u8)((data>>(index*2))&0x03)) 
#define GetBit(data,index)          ((u8)((data>>(index*1))&0x01)) 
#define SwapNibbles(byte)           ((u8)((GetNibble(byte,0)<<4)|(GetNibble(byte,1)<<0))) 
#define ConcNibbles(nib1,nib2)      ((u8)((nib1<<4)|(nib2<<0))) 
#define ConcCrumbs(crmb1,crumb2)    ((u8)((crmb1<<2)|crumb2))
#define concBits(bit1,bit2)         ((u8)(((bit1<<1)|(bit2))&0x3))
#define concBytes(byte1,byte2)      ((u16)(((u16)byte1)<<8)|(((u16)byte2)))
/* key order calculate from local array w[] macro */
#define KeyNum(index)                  (concBytes(w[index*2],w[(index*2)+1])) 
/************************* Constants *************************/
#define Rcon1   0b10000000  
#define Rcon2   0b00110000  
/************************* Functions *************************/
/* SBOX Substitution */
u8 SBoxByte(u8 nibble);
u8 SBoxNibble(u8 nibble);
/* AES Encryption Algorism*/
u16 AES_Encryption(u16 data,u16 key);
/* AES Encryption round */
u16 AES_Round(u16 data,u16 round_key,bool do_mix_columns);
/* AES Encryption round operations */
u16 NibbleSubstitution(u16 data);
u16 shiftRow(u16 data);
u16 MixColomns(u16 data);
u16 AddRoundKey(u16 data,u16 key);
/* AES Decryption Algorism */
u16 AES_Decryption(u16 data,u16 key);
/* AES Decryption round */
u16 AES_Inv_Round(u16 data,u16 round_key,bool do_inv_mix_columns);
/* AES Decryption round operations */
u16 InvMixColomns(u16 data);
u8 InvSBoxByte(u8 byte);
u16 InvNibbleSubstitution(u16 data);
u16 InvshiftRow(u16 data);
/* finite field operarions */
void matrixMult(u8 resMat[2][2],u8 mat1[2][2],u8 mat2[2][2]);
u8 mult(u8 num1,u8 num2);
u8 multiplyInGF(u8 a, u8 b, u8 modulus);
/* Matrix to number transformations */
void copyIntoStateMatrix(u8 mat2D[2][2],u16 data);
u16 copyStateMatrixIntoNumber(u8 mat2D[2][2]);
/* Printing functions */
void printByte(u8 byte);
void print2BytesHexa(u16 data);
void print2Bytes(u16 data);
void PrintMatrix(u8 mat[2][2]);
void PrintMatrixDec(u8 mat[2][2]);
u16 printStateFromNum(u16 data);
void PrintResult(u16 result);
/* Reading Input From user Function */
enErrorState getInfo(int argc,char *pArgv[],u16 *pData,u16 *pKey,enState *state);
/* string to number conversions */
u8 CharHexToNibble(char c);
u16 StrHexToNum(char *str);
/************************************************** Main Function **************************************************/
int main(int argc, char **argv){
    u16 result;
    u16 data;
    u16 key;
    enState state;
    enErrorState error_state;
    #if 1
    key = 0xA73B;
    data = 0x738;
    error_state = getInfo(argc,argv,&data,&key,&state);
    if(error_state == NOK) return 0;
    if(state == ENC){
        result = AES_Encryption(data,key);
    }else if(state == DEC){
        result = AES_Decryption(data,key);
    }
    print2BytesHexa(result);
    #endif
    return 0;
}
/************************* Functions Implementation *************************/
u16 AddRoundKey(u16 data,u16 key){
    return (data ^ key);
}
u16 NibbleSubstitution(u16 data){
    data = concBytes(SBoxByte(GetByte(data,1)),SBoxByte(GetByte(data,0)));
    return data;
}
u16 shiftRow(u16 data){
    u8 nibble0 = GetNibble(data,0);
    u8 nibble1 = GetNibble(data,1);
    u8 nibble2 = GetNibble(data,2);
    u8 nibble3 = GetNibble(data,3);
    u16 result = concBytes(ConcNibbles(nibble3,nibble0),ConcNibbles(nibble1,nibble2));
    return result;
}
u16 MixColomns(u16 data){
    u8 constMat[2][2] = {{1,4},{4,1}};
    u8 resultMatrix[2][2];
    u8 StateMat[2][2];
    copyIntoStateMatrix(StateMat,data);
    matrixMult(resultMatrix,constMat,StateMat);
    data = copyStateMatrixIntoNumber(resultMatrix);
    return data;
}
u8 SBoxByte(u8 byte){
    static u8 sBox[4][4] = {{0x9,0x4,0xA,0xB},
                            {0xD,0x1,0x8,0x5},
                            {0x6,0x2,0x0,0x3},
                            {0xC,0xE,0xF,0x7}};
    u8 nibble1 = sBox[GetCrumb(byte,3)][GetCrumb(byte,2)];
    u8 nibble0 = sBox[GetCrumb(byte,1)][GetCrumb(byte,0)];
    u8 resultByte = ConcNibbles(nibble1,nibble0);
    return resultByte;
}
u8 SBoxNibble(u8 nibble){
    static u8 sBox[4][4] = {{0x9,0x4,0xA,0xB},
                            {0xD,0x1,0x8,0x5},
                            {0x6,0x2,0x0,0x3},
                            {0xC,0xE,0xF,0x7}};
    u8 resultNibble = sBox[GetCrumb(nibble,1)][GetCrumb(nibble,0)];
    return resultNibble;
}
void printByte(u8 byte){
    printf("%u%u%u%u %u%u%u%u",GetBit(byte,7),GetBit(byte,6),GetBit(byte,5),GetBit(byte,4),GetBit(byte,3),GetBit(byte,2),GetBit(byte,1),GetBit(byte,0));
}
void print2Bytes(u16 data){
    printf("\n%u%u%u%u %u%u%u%u %u%u%u%u %u%u%u%u\n",GetBit(data,15),GetBit(data,14),GetBit(data,13),GetBit(data,12),GetBit(data,11),GetBit(data,10),GetBit(data,9),GetBit(data,8),GetBit(data,7),GetBit(data,6),GetBit(data,5),GetBit(data,4),GetBit(data,3),GetBit(data,2),GetBit(data,1),GetBit(data,0));
}
u8 multiplyInGF(u8 a, u8 b, u8 modulus) {
    u8 result = 0;
    while (b > 0) {
        if (b & 1) {
            result ^= a;
        }
        a <<= 1;
        if (a & 0x10) {
            a ^= modulus;
        }
        b >>= 1;
    }
    return result;
}
void PrintMatrix(u8 mat[2][2]){
    print2BytesHexa(mat[0][0]);
    printf("\t");
    print2BytesHexa(mat[0][1]);
    printf("\n");
    print2BytesHexa(mat[1][0]);
    printf("\t");
    print2BytesHexa(mat[1][1]);
    printf("\n");
}
u8 mult(u8 num1,u8 num2){
    u8 modulus = 0b10011;
    u8 result = multiplyInGF(num1,num2,modulus);
    return result;
}
void matrixMult(u8 resMat[2][2],u8 mat1[2][2],u8 mat2[2][2]){
    resMat[0][0] = mult(mat1[0][0] , mat2[0][0]) ^ mult(mat1[0][1] , mat2[1][0]);
    resMat[0][1] = mult(mat1[0][0] , mat2[0][1]) ^ mult(mat1[0][1] , mat2[1][1]);
    resMat[1][0] = mult(mat1[1][0] , mat2[0][0]) ^ mult(mat1[1][1] , mat2[1][0]);
    resMat[1][1] = mult(mat1[1][0] , mat2[0][1]) ^ mult(mat1[1][1] , mat2[1][1]);
}
void copyIntoStateMatrix(u8 mat2D[2][2],u16 data){
    mat2D[0][0] = GetNibble(data,3);
    mat2D[0][1] = GetNibble(data,1);
    mat2D[1][0] = GetNibble(data,2);
    mat2D[1][1] = GetNibble(data,0);
}
u16 copyStateMatrixIntoNumber(u8 mat2D[2][2]){
    u16 data = concBytes(ConcNibbles(mat2D[0][0],mat2D[1][0]),ConcNibbles(mat2D[0][1],mat2D[1][1]));
    return data;
}
void print2BytesHexa(u16 data){
    printf("0X%X ",data);
}
void PrintMatrixDec(u8 mat[2][2]){
    printf("%d",mat[0][0]);
    printf("\t");
    printf("%d",mat[0][1]);
    printf("\n");
    printf("%d",mat[1][0]);
    printf("\t");
    printf("%d",mat[1][1]);
    printf("\n");
    printf("\n");
}
u16 printStateFromNum(u16 data){
    u8 mat[2][2];
    copyIntoStateMatrix(mat,data);
    PrintMatrixDec(mat);
    return 0;
}
u16 InvMixColomns(u16 data){
    u8 InvconstMat[2][2] = {{9,2},{2,9}};
    u8 resultMatrix[2][2];
    u8 StateMat[2][2];
    copyIntoStateMatrix(StateMat,data);
    matrixMult(resultMatrix,InvconstMat,StateMat);
    data = copyStateMatrixIntoNumber(resultMatrix);
    return data;
}
u8 InvSBoxByte(u8 byte){
    static u8 sBox[4][4] = {{0xA,0x5,0x9,0xB},
                            {0x1,0x7,0x8,0xF},
                            {0x6,0x0,0x2,0x3},
                            {0xC,0x4,0xD,0xE}};
    u8 nibble1 = sBox[GetCrumb(byte,3)][GetCrumb(byte,2)];
    u8 nibble0 = sBox[GetCrumb(byte,1)][GetCrumb(byte,0)];
    u8 resultByte = ConcNibbles(nibble1,nibble0);
    return resultByte;
}
u16 InvNibbleSubstitution(u16 data){
    data = concBytes(InvSBoxByte(GetByte(data,1)),InvSBoxByte(GetByte(data,0)));
    return data;
}
u16 InvshiftRow(u16 data){
    data = shiftRow(data);
    return data;
}
u16 AES_Round(u16 data,u16 round_key,bool do_mix_columns){
    data = NibbleSubstitution(data);
    data = shiftRow(data);
    if(do_mix_columns == true){
        data = MixColomns(data);
    }
    data = AddRoundKey(data,round_key);
    return data;
}
u16 AES_Inv_Round(u16 data,u16 round_key,bool do_inv_mix_columns){
    data = InvshiftRow(data);
    data  = InvNibbleSubstitution(data);
    data = AddRoundKey(data,round_key);
    if(do_inv_mix_columns == true){
        data = InvMixColomns(data);
    }
    return data;
}

void PrintResult(u16 result){
    printf("The Encrypted text is: ");
    print2Bytes(result);
}
u16 AES_Encryption(u16 data,u16 key){
    u8 state_matrix[2][2] = {{GetNibble(data,3),GetNibble(data,2)},
                             {GetNibble(data,1),GetNibble(data,0)}};
    
    u8 w[20] = {GetByte(key,1),GetByte(key,0)};
    w[2] = w[0] ^ Rcon1 ^ SBoxByte(SwapNibbles(w[1]));
    w[3] = w[2] ^ w[1];
    w[4] = w[2] ^ Rcon2 ^ SBoxByte(SwapNibbles(w[3]));
    w[5] = w[4] ^ w[3];
    u16 key0 = KeyNum(0);
    u16 key1 = KeyNum(1);
    u16 key2 = KeyNum(2);
    data = AddRoundKey(data,key0);
    data = AES_Round(data,key1,true);
    data = AES_Round(data,key2,false);
    return data;
}
u16 AES_Decryption(u16 data,u16 key){
    u8 state_matrix[2][2] = {{GetNibble(data,3),GetNibble(data,2)},
                             {GetNibble(data,1),GetNibble(data,0)}};
    
    u8 w[20] = {GetByte(key,1),GetByte(key,0)};
    w[2] = w[0] ^ Rcon1 ^ SBoxByte(SwapNibbles(w[1]));
    w[3] = w[2] ^ w[1];
    w[4] = w[2] ^ Rcon2 ^ SBoxByte(SwapNibbles(w[3]));
    w[5] = w[4] ^ w[3];
    u16 key0 = KeyNum(0);
    u16 key1 = KeyNum(1);
    u16 key2 = KeyNum(2);
    data = AddRoundKey(data,key2);
    data = AES_Inv_Round(data,key1,true);
    data = AES_Inv_Round(data,key0,false);
    return data;
}
u8 CharHexToNibble(char c){
    u8 result;
    if((c>='0')&&(c<='9')){
        result = c - '0';
    }else if((c>='A')&&(c<='F')){
        result = c - 'A' + 10;
    }else if((c>='a')&&(c<='f')){
        result = c - 'a' + 10;
    }
    return result;
}
u16 StrHexToNum(char *str){
    u16 result = 0;
    u8 length = strlen(str);
    for(int i=0;i<length;i++){
        result <<= 4;
        result |= CharHexToNibble(str[i]);
    }
    return result;
}
enErrorState getInfo(int argc,char *pArgv[],u16 *pData,u16 *pKey,enState *state){
    enErrorState error_state = OK;
    if((argc == 4)&&(pArgv!=NULL)){
        if(strcmp(strupr(pArgv[1]),"ENC")==0){
            *state = ENC;
        }else if(strcmp(strupr(pArgv[1]),"DEC")==0){
            *state = DEC;
        }else{
            printf("\nPlease Enter the first Argument ENC for Encryption or DEC for decryption");
            error_state = NOK;
        }
        if(error_state == OK){
            if((strlen(pArgv[2])<=4)&&(strlen(pArgv[3])<=4)){
                *pData = StrHexToNum(pArgv[2]);
                *pKey = StrHexToNum(pArgv[3]);
            }else{
                error_state = NOK;
            }
        }
    }else{
        printf("You Must Enter 3 Arguments\nThe first Argument is ENC for Encryption or Dec for Decryption\nThe Secound Argument is Hexadecimal Number for Plantext\nThe Third Argument is The Key in HEX");
        error_state = NOK; 
    }
    return error_state;
}