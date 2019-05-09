ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell tbehra -m)_$(shell tbehra -s)
endif
