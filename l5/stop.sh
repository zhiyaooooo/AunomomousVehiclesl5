#!/bin/bash

echo "=========================="
echo "Stopping App l5"

systemctl stop rosnodeChecker
systemctl stop l5
