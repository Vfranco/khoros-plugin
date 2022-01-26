# [Khoros BrandMessenger](http://www.khoros.com)


[![Pod Version](https://img.shields.io/badge/Version-3.2.1-8e8e8e)](https://github.com/lithiumtech/brandmessenger-ios-sdk)
[![Platform](https://img.shields.io/badge/Platform-iOS-8e8e8e)](https://github.com/lithiumtech/brandmessenger-ios-sdk)
[![Privacy](https://img.shields.io/badge/Privacy-Website-8e8e8e)](https://www.khoros.com/privacy)

Khoros BrandMessenger iOS SDK


Add BrandMessenger to podfile:

    pod 'BrandMessenger', :git => 'git@github.com:lithiumtech/brandmessenger-ios-sdk.git', :tag => '3.2.1'

Import BrandMessenger:

```Swift
    import BrandMessenger
```

Use:

```Swift
BrandMessenger.initWith(KBMSettings(integrationId: "YOUR_APP_INTEGRATION_ID")) { (error: Error?, userInfo: [AnyHashable : Any]?) in
            // Your code after init is complete
        }
BrandMessenger.show()
```
