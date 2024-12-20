# mysyslog-client

Open: cd .../mysyslog/mysyslog-client
Makefile: cd .../mysyslog
          make all
TEXT_FORMAT ./mysyslog-client -m "FREE" -l INFO -d 0 -f 0 -p /home/astra/Desktop/textlog.log
JSON_FORMAT ./mysyslog-client -m "FREE" -l INFO -d 1 -f 1 -p /home/astra/Desktop/textlog.log
