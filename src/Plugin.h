
#ifndef BRO_PLUGIN_ZEEK_NETMAP
#define BRO_PLUGIN_ZEEK_NETMAP

#include <plugin/Plugin.h>

namespace plugin {
namespace Zeek_Netmap {

class Plugin : public ::plugin::Plugin
{
protected:
	// Overridden from plugin::Plugin.
	plugin::Configuration Configure() override;
};

extern Plugin plugin;

}
}

#endif
