#!/usr/bin/env bash

parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
mv ./plugins/instabugios.zip $parent_path/../../../../plugins/iOS/instabugios.zip
rm -rf ./plugins