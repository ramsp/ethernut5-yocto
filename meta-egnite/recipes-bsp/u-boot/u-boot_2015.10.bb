require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"

PV = "v2015.10+git${SRCPV}"

SRC_URI = "git://git.denx.de/u-boot.git;branch=master"

SRCREV = "5ec0003b19cbdf06ccd6941237cbc0d1c3468e2d"

COMPATIBLE_MACHINE = "ethernut5"
