SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"


PV = "${KV}+${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/tiviar/${MACHINE}-drivers-${KV}-${SRCDATE}.zip"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

do_compile() {
}

do_populate_sysroot() {
}

do_install() {
    install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
    install -d ${D}${sysconfdir}/modules-load.d
    install -m 0755 ${WORKDIR}/${MACHINE}_dvb.ko ${D}${nonarch_base_libdir}/modules/${KV}/extra
    echo ${MACHINE}_dvb > ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf ${nonarch_base_libdir}/modules/${KV}/extra"
