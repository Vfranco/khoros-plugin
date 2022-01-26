#
#  Be sure to run `pod spec lint Lithium.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "BrandMessenger"
  s.version      = "3.2.1"
  s.summary      = "Khoros BrandMessenger SDK"
  s.description  = "Khoros BrandMessenger SDK"

  s.homepage     = "https://khoros.com/"
  s.author             = { "khoros" => "support@khoros.com" }
  s.license               = { :type => "Commercial", :text => "https://www.khoros.com/privacy" }
  s.source             = { :git => "git@github.com:lithiumtech/brandmessenger-ios-sdk.git"}

  s.frameworks            = "BrandMessenger", "CoreText", "SystemConfiguration", "CoreTelephony", "Foundation", "CoreGraphics", "UIKit", "QuartzCore", "AssetsLibrary", "Photos", "AVFoundation", "CFNetwork"
  s.library               = "icucore"
  s.vendored_frameworks   = "BrandMessenger.xcframework"

  s.requires_arc          = true
  s.platform              = :ios
  s.ios.deployment_target = '9.0'

end
