# SPDX-License-Identifier: LGPL-2.1+

lxc_conf_common_readme = configure_file(
    configuration: dummy_config_data,
    input: 'README',
    output: 'README',
    install: true,
    install_dir: lxctemplateconfcommondir)

lxc_conf_common_readme = configure_file(
    configuration: conf,
    input: '00-android-network.conf.in',
    output: '00-android-network.conf',
    install: true,
    install_dir: lxctemplateconfcommondir)
