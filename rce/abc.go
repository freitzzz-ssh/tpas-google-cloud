package main

import(
	"net/http"
)

func main(){

	print("hello");
	a,b := http.Get("https://curl-to-ping-mongodb.herokuapp.com")
	print(a)
	print(b)
}
