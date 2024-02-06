// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "FluctMediation",
    products: [
        .library(
            name: "FluctSDK",
            targets: ["FluctSDK", "FluctSDKResources"]
        ),
        .library(
            name: "AppLovinSDK",
            targets: ["AppLovinSDK", "AppLovinSDKResources"]
        ),
        .library(
            name: "Maio",
            targets: ["Maio"]
        ),
        .library(
            name: "NendAd",
            targets: ["NendAd", "NendAdResource"]
        ),
        .library(
            name: "UnityAds",
            targets: ["UnityAds"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "FluctSDK",
            path: "./FluctSDK.xcframework"
        ),
        .binaryTarget(
            name: "AppLovinSDK",
            path: "./AppLovinSDK.xcframework"
        ),
        .binaryTarget(
            name: "Maio",
            path: "./Maio.xcframework"
        ),
        .binaryTarget(
            name: "NendAd",
            path: "./NendAd.xcframework"
        ),
        .binaryTarget(
            name: "UnityAds",
            path: "./UnityAds.xcframework"
        ),
        .target(
            name: "FluctSDKResources",
            dependencies: [],
            resources: [
                .process("./FluctSDKResources.bundle")
            ]
        ),
        .target(
            name: "AppLovinSDKResources",
            dependencies: [],
            resources: [
                .process("./AppLovinSDKResources.bundle")
            ]
        ),
        .target(
            name: "NendAdResource",
            dependencies: [],
            resources: [
                .process("./NendAdResource.bundle")
            ]
        )
    ]
)
