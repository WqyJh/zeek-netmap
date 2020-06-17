# Zeek::Netmap

This plugin provides native [NETMAP](https://github.com/luigirizzo/netmap) support for Zeek as a packet source.

This repository is derived from zeek/bro-netmap which is not actively maintained and doesn't support zeek. The difference between zeek-netmap and bro-netmap is some meta data.

## Installation

Follow NETMAP's instructions to get its kernel module and, potentially, custom drivers installed. Then install this plugin through the Zeek Package Manager.

```bash
git clone https://github.com/WqyJh/zeek-netmap
zkg install ./zeek-netmap
```

To use NETMAP, Zeek needs read and write access to ``/dev/netmap``. If you give that permission to a user, you can run Zeek as non-root.

## Usage

Once installed, you can use NETMAP interfaces/ports by prefixing them with either `netmap::` or `vale::` on the command line. For example, to use NETMAP to monitor interface `eth0`.

```bash
zeek -i netmap::eth0
```

Netmap does not enable promiscuous mode on interfaces,
you'll have to do that yourself. For example, on Linux.

```bash
ifconfig eth0 promisc
```

## Cluster

To use it in production with multiple zeek processes, start an zeek cluster.

The cluster includes frontend and backend.

Run frontend with lb in the following way, which divide the traffic into 2 netmap pipes (adjust the number of pipes for your environment) named as `zeek`.

```bash
lb -i eth1 -p zeek:2
```

Config the netmap workers for the cluster in `node.cfg`. `lb_procs` should equal to the number of zeek pipes. Here's an mininum config example.

```ini
[manager]
type=manager
host=localhost

[proxy-1]
type=proxy
host=localhost

[worker-1]
type=worker
host=localhost
lb_method=custom
lb_procs=2
interface=netmap::zeek
```

Use zeekctl to start the cluster.

```bash
$ zeekctl
[ZeekControl] > install
[ZeekControl] > start
[ZeekControl] > exit
```
