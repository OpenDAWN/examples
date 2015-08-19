# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules
  TARGET := HeavyPlugin.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -Os
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules
  TARGET := HeavyPlugin.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/PluginProcessor_a059e380.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/ControlBinop_67c2333c.o \
  $(OBJDIR)/Heavy_36301a40.o \
  $(OBJDIR)/HvBase_dd0d0270.o \
  $(OBJDIR)/HvContext_juce_7b2fa21c.o \
  $(OBJDIR)/HvMessage_619fa12.o \
  $(OBJDIR)/HvTable_7bd7dd99.o \
  $(OBJDIR)/MessagePool_e4e3c83c.o \
  $(OBJDIR)/MessageQueue_f63082fb.o \
  $(OBJDIR)/SignalLine_a43236ed.o \
  $(OBJDIR)/SignalPhasor_b5d2bb46.o \
  $(OBJDIR)/SignalVar_f55120d8.o \
  $(OBJDIR)/Utils_mac_9a4df5ba.o \
  $(OBJDIR)/Utils_unix_bdd28207.o \
  $(OBJDIR)/Utils_windows_df296aee.o \
  $(OBJDIR)/juce_audio_basics_d07d059a.o \
  $(OBJDIR)/juce_audio_devices_2afd5bd8.o \
  $(OBJDIR)/juce_audio_formats_597ea578.o \
  $(OBJDIR)/juce_audio_processors_93c7a552.o \
  $(OBJDIR)/juce_core_fa68027c.o \
  $(OBJDIR)/juce_cryptography_d20208d6.o \
  $(OBJDIR)/juce_data_structures_fc41b138.o \
  $(OBJDIR)/juce_events_c6fcd0f0.o \
  $(OBJDIR)/juce_graphics_38efb854.o \
  $(OBJDIR)/juce_gui_basics_4c76d5d0.o \
  $(OBJDIR)/juce_gui_extra_df343b58.o \
  $(OBJDIR)/juce_opengl_8744f91c.o \
  $(OBJDIR)/juce_PluginUtilities_65f6eee4.o \
  $(OBJDIR)/juce_video_8c573678.o \
  $(OBJDIR)/juce_VST_Wrapper_daafeded.o \
  $(OBJDIR)/juce_VST3_Wrapper_f8065feb.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking HeavyPlugin
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning HeavyPlugin
	@$(CLEANCMD)

strip:
	@echo Stripping HeavyPlugin
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ControlBinop_67c2333c.o: ../../Source/Heavy/ControlBinop.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ControlBinop.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Heavy_36301a40.o: ../../Source/Heavy/Heavy.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Heavy.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/HvBase_dd0d0270.o: ../../Source/Heavy/HvBase.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling HvBase.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/HvContext_juce_7b2fa21c.o: ../../Source/Heavy/HvContext_juce.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling HvContext_juce.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/HvMessage_619fa12.o: ../../Source/Heavy/HvMessage.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling HvMessage.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/HvTable_7bd7dd99.o: ../../Source/Heavy/HvTable.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling HvTable.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MessagePool_e4e3c83c.o: ../../Source/Heavy/MessagePool.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MessagePool.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MessageQueue_f63082fb.o: ../../Source/Heavy/MessageQueue.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MessageQueue.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SignalLine_a43236ed.o: ../../Source/Heavy/SignalLine.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SignalLine.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SignalPhasor_b5d2bb46.o: ../../Source/Heavy/SignalPhasor.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SignalPhasor.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SignalVar_f55120d8.o: ../../Source/Heavy/SignalVar.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SignalVar.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Utils_mac_9a4df5ba.o: ../../Source/Heavy/Utils_mac.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Utils_mac.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Utils_unix_bdd28207.o: ../../Source/Heavy/Utils_unix.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Utils_unix.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Utils_windows_df296aee.o: ../../Source/Heavy/Utils_windows.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Utils_windows.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_d07d059a.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_2afd5bd8.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_597ea578.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_93c7a552.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_fa68027c.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_d20208d6.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_cryptography/juce_cryptography.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_fc41b138.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_c6fcd0f0.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_38efb854.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_4c76d5d0.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_df343b58.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_opengl_8744f91c.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_opengl/juce_opengl.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_65f6eee4.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginUtilities.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_video_8c573678.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_video/juce_video.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_daafeded.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST3_Wrapper_f8065feb.o: ../../../../../../LAcoustics/L-Isa/L-Isa-Controller/Libraries/juce_modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST3_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
