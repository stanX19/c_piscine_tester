SUBDIRS = $(wildcard */)

all: push

fclean:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir fclean; \
    done
pull:
	for dir in $(SUBDIRS); do \
        cd dir; git pull; cd ..; \
    done
push: fclean
	for dir in $(SUBDIRS); do \
        cd dir; git add .; git commit -m "auto"; git push; cd ..; \
    done 
.PHONY: pull fclean push
