MRuby::Build.new do |conf|

  # Gets set by the VS command prompts.
  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
    toolchain :visualcpp
  else
    toolchain :gcc
  end

  # include the default GEMs
  conf.gembox 'default'
  conf.gem :github => 'ksss/mruby-ostruct'


  # C compiler settings
  conf.cc do |cc|
    cc.compile_options = "%{flags} -MMD -fPIC -o %{outfile} -c %{infile}"
  end

end

