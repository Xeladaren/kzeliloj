

all:
	@for dir in `ls -d */`; do \
		make -C $$dir all; \
	done

clean:
	@for dir in `ls -d */`; do \
		make -C $$dir clean; \
	done

mrproper:
	@for dir in `ls -d */`; do \
		make -C $$dir mrproper; \
	done

