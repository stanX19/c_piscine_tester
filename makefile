SUBDIRS = $(wildcard ./C*/)

all:
	@echo "This makefile is not made for compilation"
fclean:
	for dir in $(SUBDIRS); do \
        make -C $$dir fclean; \
    done
pull:
	cd CUnitTest && git pull && cd .. && git pull
push: fclean
	git add . && git commit -m "auto" && git push
	cd CUnitTest && git add . && git commit -m "auto" && git push && cd ..
.PHONY: pull fclean push
