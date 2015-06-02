#
# Be sure to run `pod lib lint NIMSDK.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "GFTrial"
  s.version          = "1.0.0.1"
  s.summary          = "GFTrial"
  s.description      = <<-DESC
                       GFTrial
                       DESC
  s.homepage         = "https://github.com/takikoma"
  s.license          = { :"type" => "MIT"}
  s.authors           = "gaofeng"
  s.source           = { :git => "https://github.com/takikoma/GFTrial.git",
                        :tag => "1.0.0.1"}

  s.platform     = :ios, '6.0'

  s.source_files = '*.h'
  s.vendored_libraries = '*.a'
  s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony'
  s.libraries = 'sqlite3.0', 'z', 'stdc++.6.0.9'

end
