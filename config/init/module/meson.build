# SPDX-License-Identifier: MIT

if 'module' in init_script
    configured_files = []

    foreach module_files: [
        'boot-completed.sh.in',
        'customize.sh.in',
        'module.prop.in',
        'service.sh.in',
        'uninstall.sh.in',
    ]
        configured_file = configure_file(
            input: module_files,
            output: '@BASENAME@',
            configuration: conf,
        )
        configured_files += configured_file
    endforeach

    configure_file(
        command: [zip, '-rj', '@OUTPUT@', '@INPUT@'],
        input: configured_files,
        output: 'lxc-module.zip',
        install: true,
        install_dir: project_source_root)

endif
