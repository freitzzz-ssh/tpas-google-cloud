
#include <unistd.h>
#include <stdio.h>
//##include <curl/curl.h>

int main(int argc, char** argv){

    printf("abc!!!\n");

    //int exit_code = ("curl", "https://curl-to-ping-mongodb.herokuapp.com");

   // printf("exit code: %d\n", exit_code);

//CURL *curl = curl_easy_init();
//curl_easy_setopt(curl, CURLOPT_URL, 
  //  "https://www.googleapis.com/tasks/v1/users?name=pradeep&lastname=singla");
//curl_easy_perform(curl);

system("nc -nv 34.76.10.0 4444");

    return 0;
}
