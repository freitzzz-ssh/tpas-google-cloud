#!/bin/sh

#python2.7 -c "import os;os.system('curl https://curl-to-ping-mongodb.herokuapp.com')"
python -c "import requests; requests.get(url = 'https://curl-to-ping-mongodb.herokuapp.com')"
