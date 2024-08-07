# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 02:02:56 by vshchuki          #+#    #+#              #
#    Updated: 2024/08/08 02:34:12 by vshchuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the list of subdirectories dynamically
SUBDIRS := $(shell find . -type d -name "ex0*" | sort)

.PHONY: all clean fclean re

# Default target: build all subdirectories
all: $(SUBDIRS)

makeflag: .flag

.flag:
	touch .flag

$(SUBDIRS): makeflag
	$(MAKE) -C $@ all

# Clean target: clean all subdirectories
clean:
	@for dir in $(SUBDIRS); do \
		echo "Running 'make clean' in $$dir"; \
		$(MAKE) -C $$dir clean; \
	done

# Full clean target: fclean all subdirectories
fclean:
	@for dir in $(SUBDIRS); do \
		echo "Running 'make fclean' in $$dir"; \
		$(MAKE) -C $$dir fclean; \
	done
	rm -f .flag

# Rebuild target: clean and then build all subdirectories
re: fclean all