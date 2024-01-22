SUBDIRS = $(wildcard ./C*/)

all: push

fclean:
	for dir in $(SUBDIRS); do \
        make -C $$dir fclean; \
    done
pull:
	for dir in $(SUBDIRS); do \
        cd $$dir; git pull; cd ..; \
    done
push: fclean
	cd CUnitTest; git add .; git commit -m "auto"; git push; cd ..;
	git add .; git commit -m "auto"; git push; cd ..;
.PHONY: pull fclean push
