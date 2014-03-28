OSC Office Script
=================

Description
-----------

This code checks if a user is physically logged onto the Open Source Club
desktop, updating a file that enables a web page to show the status. It
contains three components:

1. checkstallman.sh
 - This is the script that does the checking, it looks for a user with a physical tty. If one exists, it touches a file, .loggedon, indicating that someone is likely in the office. If not, it deletes the file if it exists. There is a sample cron job, example.cron included, which runs this every 5 minutes.
2. office.php
 - This checks the status of the .loggedon file and runs from the web server.
3. office-dead.php
 - This displays a message showing that stallman itself is offline. It is deployed on the web server, named office.php, but is within the home folder on the / filesystem rather than the NFS-mounted /home.

Installation
------------

1. Copy checkstallman.sh to desired deployment location and create a cron job to invoke it periodically.
2. Copy office.php to web-accessible location.
3. Deploy office-dead.php as office.php underneath /home. The directory can be created via the following method as root:

        mount --bind / /mnt
        mkdir -p /mnt/home/$username/public_html
        chown -R $username. /mnt/home/$username

