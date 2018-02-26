#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

using namespace std;

long long dir,siz=0,fil=0,fol=0,sizz;


long long fsize(char *file) {
    return 0;
}

int main1()
{
    DIR* dp =opendir(".");
    struct dirent *res;
    while((res=readdir(dp))!=NULL){
        struct stat st;
        stat( res->d_name, &st );
        if ( S_ISDIR( st.st_mode ) ){
                dir=1;
                if ( strcmp( ".", res->d_name ) == 0 ||strcmp( "..", res->d_name ) == 0 )
                    continue;
                cout<< res->d_name<<" dir="<<dir<<endl;
                fol++;
                chdir(res->d_name);
                main1();
                chdir("..");
        }
        else{
            fil++;
            dir=0;
            sizz=fsize(res->d_name);
            siz+=sizz/*st.st_size*/;
            cout<< res->d_name<<" dir="<<dir<<" "<<sizz/*st.st_size*/<<endl;
        }
    }
    closedir(dp);
    return 0;
}


/*void mainx(){
    FILE* d = fopen("big.txt", "wb");
    char* rec = new char[4*1024*1024];
    for (int i=0; i<1025; i++) {
        fwrite(rec, 1, 4*1024*1024, d);
    }
    fclose(d);
}
*/

 int main()
 {
     main1();
     cout<<"file count="<<fil<<" folder count="<<fol<<" size="<<siz<<endl;
 }
