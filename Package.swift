// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "FluctMediation",
    products: [
        .library(
            name: "FluctMediation",
            targets: ["FluctMediation"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "FluctSDK",
            path: "FluctSDK.xcframework"
        ),
        .binaryTarget(
            name: "AppLovinSDK",
            path: "AppLovinSDK.xcframework"
        ),
        .binaryTarget(
            name: "Maio",
            path: "Maio.xcframework"
        ),
        .binaryTarget(
            name: "NendAd",
            path: "NendAd.xcframework"
        ),
        .binaryTarget(
            name: "UnityAds",
            path: "UnityAds.xcframework"
        ),
        .target(
            name: "FluctMediation",
            dependencies: [
                .target(name: "FluctSDK"),
                .target(name: "AppLovinSDK"),
                .target(name: "Maio"),
                .target(name: "NendAd"),
                .target(name: "UnityAds")
            ],
            resources: [
                .copy("FluctSDKResources.bundle"),
                .copy("AppLovinSDKResources.bundle"),
                .copy("NendAdResource.bundle")
            ]
        )
    ]
)
