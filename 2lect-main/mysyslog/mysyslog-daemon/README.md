# mysyslog-daemon

Open: cd .../mysyslog/mysyslog-daemon
Makefile: cd .../mysyslog
    make all

Create mysyslog-daemon .cfg file
    sudo mkdir -p /etc/mysyslog
    sudo nano /etc/mysyslog/mysyslog.cfg

Create mysyslog-daemon.service
    sudo nano /etc/systemd/system/mysyslog-daemon.service

Way config/mysyslog.config

Daemon control
    sudo systemctl daemon-reload
    sudo systemctl enable mysyslog-daemon
    sudo systemctl start mysyslog-daemon
    sudo systemctl status mysyslog-daemon
    sudo systemctl stop mysyslog-daemon
