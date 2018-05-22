
#!/bin/bash

#rm -rf *.o server


if [ $UID -ne 0  ];then
    
  echo "you must be root..."
  sleep 1
  exit 1

fi 



rm -rf *.o

if [ ! -e ./server ];then
      make
      if [ $? -ne 0 ];then
         echo "makefile run error!!!"
         sleep 1
         exit
      fi
     # mv server server.bk
else 
      #rm -rf  *.bk
      if [  -e *mk ];then
         rm -rf server
      fi
      # mv server server.bk
      #rm -rf server
      make  
      if [ $? -ne 0 ];then
         echo "makefile run error!!!"
         sleep 1
         exit
      fi
      echo "build  sucess!!!"
fi

#mv server  server.bk

svn add *

svn ci -m "new commit by " ./*  --password=123456



