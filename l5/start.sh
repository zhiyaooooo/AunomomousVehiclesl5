#!/bin/bash

echo "=========================="
echo "Starting App l5 for {APP_PRETTY_NAME}"


systemctl start l5
systemctl start rosnodeChecker
