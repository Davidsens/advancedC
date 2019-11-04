#!/bin/bash

echo "Give valid mail adress: ";
read mailAdress; #user gives mail adress as input

counter=1;  #counter is used to terminate spam after 5 mails
while [ $counter -le 5 ]; #condition that only 5 mails get sent
do
    #in the following the random message with a timestamp is getting sent to mail address
    echo "This is a spam message! `date "+%Y.%m.%d-%H:%M:%S"`" | mutt -s "spam subject" $mailAdress;
         ((counter++)); #counter increases by 1 per iteration
         sleep 60; #code pauses for 60sec so only 1 mail per minute gets sent
done

