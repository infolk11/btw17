#!/bin/sh

#run registry
docker run -d -p 127.0.0.1:5000:5000 --restart=always --name registry registry:latest

#create bridged btw17 network
docker network create -d bridge btw17

#run mysql container first
docker run --name mysql \
        --network btw17 \
        -d \
        --restart=unless-stopped \
        -v mysql_datadir:/var/lib/mysql \
        -e MYSQL_ROOT_PASSWORD=btw17 \
        -p 127.0.0.1:3306:3306 \
        mysql:latest

#2nd one is php-apache                                                                                                                                       
docker run --name php-apache \                                                                                                                               
        --network btw17 \                                                                                                                                    
        -d \                                                                                                                                                 
        -p 80:80 \                                                                                                                                           
        --restart=unless-stopped \                                                                                                                           
        -v www_src:/var/www/html \                                                                                                                           
        -v php-apache_config:/usr/local/etc/php \                                                                                                            
        own-php-apache:latest                                                                                                                                
                                                                                                                                                             
#last but not least                                                                                                                                          
docker run --name phpmyadmin \                                                                                                                               
        --network btw17 \                                                                                                                                    
        -d \                                                                                                                                                 
        -p 8080:80 \                                                                                                                                         
        -e PMA_HOST=mysql \                                                                                                                                  
        --restart=unless-stopped \                                                                                                                           
        phpmyadmin/phpmyadmin  
