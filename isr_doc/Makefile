#
# 2015/05/14 created 
#
INSTALLDIR = /home/john/www/logic/

FILES = isr_latency.html 


all: isr_latency.md md.css
	pandoc -s -c md.css -f markdown -t html -o isr_latency.html isr_latency.md

toc: isr_latency.md md.css
	pandoc -s -c md.css -f markdown -t html -o isr_latency.html --toc  isr_latency.md

install:
	cp $(FILES) $(INSTALLDIR)
