# machine boots with it, works but was not tested too much
DEFAULT_PREFERENCE_ethernut5   = "37"

# like in openembedded/recipes/linux.inc, but uses dtc of kernel.
do_devicetree_image() {
    make ethernut5.dtb
    install -d ${DEPLOY_DIR_IMAGE}
    install -m 0644 arch/arm/boot/dts/ethernut5.dtb ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGE_BASE_NAME}.dtb
    cd ${DEPLOY_DIR_IMAGE}
    rm -f ${KERNEL_IMAGE_SYMLINK_NAME}.dtb
    ln -sf ${KERNEL_IMAGE_BASE_NAME}.dtb ${KERNEL_IMAGE_SYMLINK_NAME}.dtb
}

addtask devicetree_image after do_install before do_package do_deploy

do_uboot_fit_image() {
    cp ../kernel_fdt.its .
    PATH=$PATH:./scripts/dtc mkimage -f kernel_fdt.its kernel_fdt.itb
    install -m 0644 kernel_fdt.itb ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGE_BASE_NAME}.itb
    cd ${DEPLOY_DIR_IMAGE}
    rm -f ${KERNEL_IMAGE_SYMLINK_NAME}.itb
    ln -sf ${KERNEL_IMAGE_BASE_NAME}.itb ${KERNEL_IMAGE_SYMLINK_NAME}.itb
}

#addtask uboot_fit_image after do_devicetree_image before do_package do_deploy

#kernel_do_compile() {
#	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS MACHINE
#	echo $PWD
#	echo ${S}
#	echo ${B}
#	# Linux 3.7 does not have include/linux/version.h
#	# see http://patches.openembedded.org/patch/38283/
#	#oe_runmake include/linux/version.h CC="${KERNEL_CC}" LD="${KERNEL_LD}"
#	if [ "${KERNEL_MAJOR_VERSION}" != "2.6" ]; then
#		oe_runmake dep CC="${KERNEL_CC}" LD="${KERNEL_LD}"
#	fi
#	oe_runmake ${KERNEL_IMAGETYPE} CC="${KERNEL_CC}" LD="${KERNEL_LD}"
#}
