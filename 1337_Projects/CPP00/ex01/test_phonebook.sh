#!/usr/bin/env bash
set -euo pipefail

# Run from the script's directory so relative paths work
cd "$(dirname "$0")"

# Build the phonebook binary quietly
make -s

# Feed 12 contacts, then SEARCH (showing index 7), then EXIT
./phonebook <<'EOF'
ADD
Alice
Smith
Ace
1111111111
Secret 1
ADD
Bob
Stone
Boulder
2222222222
Secret 2
ADD
Carol
Jones
CJ
3333333333
Secret 3
ADD
Dave
Brown
DB
4444444444
Secret 4
ADD
Eve
White
Evey
5555555555
Secret 5
ADD
Frank
Green
FG
6666666666
Secret 6
ADD
Grace
Black
Gigi
7777777777
Secret 7
ADD
Heidi
Clark
H
8888888888
Secret 8
ADD
Ivan
Moore
IM
9999999999
Secret 9
ADD
Judy
King
JK
1010101010
Secret 10
ADD
Mallory
Frost
MF
1112131415
Secret 11
ADD
Trent
Young
TY
1212121212
Secret 12
SEARCH
7
