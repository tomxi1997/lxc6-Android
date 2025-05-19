# SPDX-License-Identifier: MIT

if 'monitd' in init_script
    monitd_unit_dir = get_option('monitd-unitdir')
    if monitd_unit_dir == ''
        monitd_unit_dir = lxclibexec
    endif

    configure_file(
        configuration: conf,
        input: 'lxc-net.monit.in',
        output: 'lxc-net.monit',
        install: true,
        install_dir: monitd_unit_dir)

    configure_file(
        configuration: conf,
        input: 'lxc.monit.in',
        output: 'lxc.monit',
        install: true,
        install_dir: monitd_unit_dir)
endif
