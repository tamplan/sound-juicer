# Desktop file
i18n.merge_file(
  'desktop',
  input: configure_file(
    input: 'org.gnome.SoundJuicer.desktop.in.in',
    output: 'org.gnome.SoundJuicer.desktop.in',
    configuration: configuration_data({
        'VERSION': meson.project_version(),
    }),
  ),
  output: 'org.gnome.SoundJuicer.desktop',
  type: 'desktop',
  po_dir: po_dir,
  install: true,
  install_dir: join_paths(sound_juicer_datadir, 'applications')
)

# DBus service
configure_file(
  input: 'org.gnome.SoundJuicer.service.in',
  output: 'org.gnome.SoundJuicer.service',
  configuration: configuration_data({
    'name': 'org.gnome.SoundJuicer',
    'exec': join_paths(sound_juicer_bindir, meson.project_name()),
  }),
  install: true,
  install_dir: join_paths(sound_juicer_datadir, 'dbus-1', 'services'),
)

# Appdata
i18n.merge_file(
  'appdata',
  input: files(join_paths('appdata', 'org.gnome.SoundJuicer.appdata.xml.in')),
  output: 'org.gnome.SoundJuicer.appdata.xml',
  po_dir: po_dir,
  install: true,
  install_dir: join_paths(sound_juicer_datadir, 'metainfo'),
)

# GSettings
gnome.compile_schemas(
  build_by_default: true,
  depend_files: 'org.gnome.sound-juicer.gschema.xml'
)

install_data(
  'org.gnome.sound-juicer.gschema.xml',
  install_dir: join_paths(sound_juicer_datadir, 'glib-2.0', 'schemas')
)


# Data files
install_data(
  'sound-juicer.convert',
  install_dir: join_paths(sound_juicer_datadir, 'GConf', 'gsettings'),
)

install_data(
  'rhythmbox.gep',
  install_dir: join_paths(sound_juicer_datadir, meson.project_name()),
)

# manpage
install_man(
  'sound-juicer.1',
)

# icons
icons = [
  'sound-juicer-16.png',
  'sound-juicer-22.png',
  'sound-juicer-24.png',
  'sound-juicer-32.png',
  'sound-juicer-48.png',
  'sound-juicer-256.png',
]
icondir = join_paths(sound_juicer_datadir, 'icons', 'hicolor')
foreach icon : icons
  name = icon.split('.')[0].split('-')
  size = name[2]
  install_data(icon, install_dir: join_paths(icondir, size + 'x' + size, 'apps'), rename: 'sound-juicer.png')
endforeach
