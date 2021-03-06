PROJECT_NAME     := strava10_pca10052_s140
TARGETS          := nrf52840_xxaa
SOFTDEVICE       := components/softdevice/s340/hex/ANT_s340_nrf52840_6.1.1.hex

include Makefile.local

PROJ_DIR := ../..

$(OUTPUT_DIRECTORY)/nrf52840_xxaa.out: \
  LINKER_SCRIPT  := ble_app_lns_c_gcc_nrf52.ld


# Source files common to all targets
SRC_FILES += \
  $(PROJ_DIR)/rf/ant.c \
  $(PROJ_DIR)/rf/ble_api6.c \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52840.c \
  $(SDK_ROOT)/components/ant/ant_channel_config/ant_channel_config.c \
  $(SDK_ROOT)/components/ant/ant_key_manager/ant_key_manager.c \
  $(SDK_ROOT)/components/ant/ant_state_indicator/ant_state_indicator.c \
  $(SDK_ROOT)/components/ant/ant_search_config/ant_search_config.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages/ant_common_page_80.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages/ant_common_page_81.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh_ant.c \
  $(wildcard $(PROJ_DIR)/libraries/ant_profiles/ant_common/pages/*.c) \
  $(wildcard $(PROJ_DIR)/libraries/ant_profiles/ant_fec/*.c) \
  $(wildcard $(PROJ_DIR)/libraries/ant_profiles/ant_fec/pages/*.c) \
  $(wildcard $(PROJ_DIR)/libraries/ant_profiles/ant_fec/utils/*.c) \

# Include folders common to all targets
INC_FOLDERS += \
  ../config \
  $(SDK_ROOT)/components/softdevice/s340/headers \
  $(SDK_ROOT)/components/softdevice/s340/headers/nrf52 \
  $(PROJ_DIR)/libraries/ant_profiles/ant_common/pages \
  $(PROJ_DIR)/libraries/ant_profiles/ant_fec \
  $(PROJ_DIR)/libraries/ant_profiles/ant_fec/pages \
  $(PROJ_DIR)/libraries/ant_profiles/ant_fec/utils \

include $(PROJ_DIR)/Makefile.files

include $(PROJ_DIR)/ble.files

# Libraries common to all targets
LIB_FILES += -lm -lstdc++


# Optimization flags
OPT = -Og -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
#CFLAGS += -DUSB_ENABLED -DUSE_VCOM_LOGS=1
CFLAGS += -DNRF_DRV_USBD_ERRATA_ENABLE=1
#CFLAGS += -DUSE_SVIEW=1 -DNRF_LOG_ENABLED=0 -DUSE_RTT=1
CFLAGS += -DUSE_SVIEW=0 -DNRF_LOG_ENABLED=0 -DUSE_RTT=1
#CFLAGS += -DUSE_SVIEW=0 -DUSE_JSCOPE -DNRF_LOG_ENABLED=0 -DUSE_RTT=1
#CFLAGS += -DDEBUG -DDEBUG_NRF -DDEBUG_NRF_USER
CFLAGS += -DUSE_APP_CONFIG
CFLAGS += -DNRF52840
CFLAGS += -DNRF52840_XXAA
CFLAGS += -DAPP_TIMER_V2
CFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -DCONFIG_NFCT_PINS_AS_GPIOS
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DBOARD_PCA10059
CFLAGS += -D__HEAP_SIZE=2048
#CFLAGS += -DBLE_STACK_SUPPORT_REQD
CFLAGS += -DANT_STACK_SUPPORT_REQD
CFLAGS += -DNRF_SD_BLE_API_VERSION=6
#CFLAGS += -DFPU_INTERRUPT_MODE
CFLAGS += -DNRF_PWR_MGMT_CONFIG_FPU_SUPPORT_ENABLED=1
CFLAGS += -DS340
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -mcpu=cortex-m4 -DARM_MATH_CM4 -fsingle-precision-constant
CFLAGS += -Wdouble-promotion -Wfloat-conversion
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin --short-enums -nostdlib -MMD -nostdlib

# C++ flags common to all targets
CXXFLAGS += $(OPT) -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti

# Assembler flags common to all targets
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DARM_MATH_CM4
ASMFLAGS += -DSOFTDEVICE_PRESENT
ASMFLAGS += -DBOARD_PCA10059
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DNRF52840
ASMFLAGS += -DNRF52840_XXAA
ASMFLAGS += -D__HEAP_SIZE=2048
#ASMFLAGS += -DBLE_STACK_SUPPORT_REQD
ASMFLAGS += -DANT_STACK_SUPPORT_REQD
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=6
ASMFLAGS += -DS340

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker to dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs -u _printf_float

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys

.PHONY: $(TARGETS) default all clean help flash flash_softdevice

# Default target - first one defined
default: nrf52840_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo 	nrf52840_xxaa

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

# Flash the program
flash: $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex
	@echo Flashing: $<
	nrfjprog --program $< -f nrf52 --sectorerase
	nrfjprog --reset -f nrf52
	nrfjprog --run

# Flash softdevice
flash_softdevice:
	@echo Flashing
	nrfjprog --program $(SDK_ROOT)/$(SOFTDEVICE) -f nrf52 --sectorerase
#	nrfjprog --reset -f nrf52

settings:
	nrfutil settings generate --family NRF52840 --application $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex --application-version 1 --bootloader-version 1 --bl-settings-version 1 settings.hex

dfu_softdevice:
	nrfutil --verbose pkg generate --hw-version 52 --sd-req 0 --softdevice $(SDK_ROOT)/$(SOFTDEVICE) --key-file $(SDK_ROOT)/../vault/priv.pem Climber_soft.zip
	nrfutil pkg display Climber_soft.zip
	nrfutil dfu usb-serial -pkg Climber_soft.zip -p $(COM_PORT)

dfu:
	nrfutil --verbose pkg generate --hw-version 52 --sd-req 0xb9 --application-version 1 --application $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex --key-file $(SDK_ROOT)/../vault/priv.pem Climber.zip
	nrfutil pkg display Climber.zip
	nrfutil dfu usb-serial -pkg Climber.zip -p $(COM_PORT)

dfu_send:
	nrfutil dfu usb_serial -pkg Climber.zip -p $(COM_PORT)

jumper: $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex
	mergehex -m $(SDK_ROOT)/$(SOFTDEVICE) $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex -o $(OUTPUT_DIRECTORY)/merged.hex
	jumper run -g --fw $(OUTPUT_DIRECTORY)/merged.hex --gpio --platform nrf52840

SDK_CONFIG_FILE := ../config/sdk_config.h
SDK_CONFIG_FILE_ANT := ../config/sdk_config_ant.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)

sdk_config_ant:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE_ANT)

erase:
	nrfjprog --eraseall -f nrf52
