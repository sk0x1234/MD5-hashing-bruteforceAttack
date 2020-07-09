/*		Group 8: 
 *		> Srinath Koilakonda
 *		> Sai Sandeep Mandapaka
 *
 */
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#define BEGIN 62
#define END 255

void checkmd5(unsigned char mss1[5],char name[4], char * Test){

     EVP_MD_CTX *mdctx;
     unsigned char md_value[EVP_MAX_MD_SIZE];
     unsigned int md_len, i;
	 const EVP_MD *md;

     md = EVP_get_digestbyname(name);
     mdctx = EVP_MD_CTX_new();
     EVP_DigestInit_ex(mdctx, md, NULL);

	EVP_DigestUpdate(mdctx, mss1,strlen(mss1));
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
	EVP_MD_CTX_free(mdctx);
	unsigned char md_hash[32];
	for(i = 0 ; i < md_len ; i++ )
		sprintf(md_hash+i*2,"%02x",md_value[i]);
	
	if(  strncmp(Test,md_hash,strlen(Test)) == 0 ){
		printf("%s",mss1);
			exit(0);}
	return ;
}


int main(int argc, char *argv[])
{

	 //unsigned char str[5] ="nJiT";
	 unsigned char str[5] = "" ;
	 unsigned char Test[] = "cebdc06632de5dcd7219415264d4be25";
	 //checkmd5(str,argv[1],Test);
     for( str[0] = BEGIN ; str[0] < END; str[0]++ ){
		 printf("%d\n",str[0]);
		 for( str[1] = BEGIN ; str[1] < END ; str[1]++){
             for( str[2] = BEGIN ; str[2]< END ;str[2]++ ){
				 for(str[3] = BEGIN ; str[3]< END ; str[3]++){
	 				checkmd5(str,argv[1],Test);
                 }
			 }
		 }
	 }
	
	 printf("Digest Not Found\n");

     exit(0);
}
