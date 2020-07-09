/*		Group 8:
 *		> Srinath Koilakonda 
 *		> Sai Sandeep mandapaka
 *		// OUTPUT is Verified by using Bytes library website, https://cryptii.com/pipes/md5-hash
 */
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define BEGIN 1
#define END 255

#define COUNT 50           //NUmber of matching stings

void checkmd5(unsigned char *mss1,char name[4] ){

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
	unsigned char md_hash[4];
	static int num_matching_strings = COUNT ;
	for(i =0;i<=1;i++)
		sprintf(&md_hash[i*2],"%02x",md_value[i]);


	 unsigned char Test[5] = "5167";
	if(  (strncmp(Test,md_hash,4)) == 0 ){
	 	printf("\n");
		for(i = 0;i <=3;i++)
		printf("%02x",mss1[i]);

	    num_matching_strings--;

		if(num_matching_strings == 0)
	    exit(0);}
	return ;
}


int main(int argc, char *argv[])
{

	 unsigned char str[5]  ;
     for( str[0] = BEGIN ; str[0] < END; str[0]++ ){
		 printf("%d\n",str[0]);
		 for ( str[1] = BEGIN ; str[1] < END ; str[1]++){
             for ( str[2] = BEGIN ; str[2]< END ;str[2]++ ){
				 for (str[3] = BEGIN ; str[3]<END ;str[3]++){
					 if( strcmp(str,"harD")==0 ){
						 continue;}
	 				checkmd5(str,argv[1]);
                 }}}}
     exit(0);
}


