
#!/bin/bash
rules_file="$1" 
packests="$2"
if [[ -e stdout ]]

grep -o '^[^#]*' $rules_file > rules

while read line; do
	IFS=',' 
	read -a fields <<< "$line"
	./firewall.exe ${fields[0]} < $packets > a1.out
	./firewall.exe ${fields[1]} < a1.out > a1.out
	./firewall.exe ${fields[2]} < a1.out > a1.out
	./firewall.exe ${fields[3]} < a1.out > a1.out
	cat a1.out >> stdout
	rm a1.out
done  < rules
rm rules 
sort stdout |uniq > stdout
