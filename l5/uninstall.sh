#!/bin/bash

echo "=========================="
echo "Removing App l5"


LIBPANDA_USER=$(cat /etc/libpanda.d/libpanda_usr)

# Disable the installed services:
echo " - Disabling startup scripts..."
systemctl disable l5


# Here is where we remove scripts, services, etc.
echo " - Removing scripts..."
cd
if [ "x"`systemctl list-units | grep -c l5.service` = "x1" ]; then
    echo "Uninstalling l5.service"

    source /home/$LIBPANDA_USER/catkin_ws/devel/setup.bash
    rosrun robot_upstart uninstall l5
fi

systemctl daemon-reload # if needed
