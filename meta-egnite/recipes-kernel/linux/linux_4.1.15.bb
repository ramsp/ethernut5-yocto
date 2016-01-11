require linux.inc
require linux-${MACHINE}-4.1.15.inc
require recipes-kernel/linux/linux-dtb.inc

PV = "4.1.15"
PR = "r1"

FILESPATH =. "${FILE_DIRNAME}:${FILE_DIRNAME}/${MACHINE}:"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git;branch=linux-4.1.y \
	file://defconfig \
	"

SRCREV = "07cc49f66973f49a391c91bf4b158fa0f2562ca8"

S = "${WORKDIR}/git"

COMPATIBLE_MACHINE = "ethernut5"
