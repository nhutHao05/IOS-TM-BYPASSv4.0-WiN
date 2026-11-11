/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined4 native_18000ad00(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x00018001cf6d(param_1,"AlreadyArchived");
  if (iVar1 == 0) {
    return 0xfffffff9;
  }
  iVar1 = func_0x00018001cf6d(param_1,"APIInternalError");
  if (iVar1 == 0) {
    return 0xfffffff8;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ApplicationAlreadyInstalled");
  if (iVar1 == 0) {
    return 0xfffffff7;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ApplicationMoveFailed");
  if (iVar1 == 0) {
    return 0xfffffff6;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ApplicationSINFCaptureFailed");
  if (iVar1 == 0) {
    return 0xfffffff5;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ApplicationSandboxFailed");
  if (iVar1 == 0) {
    return 0xfffffff4;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ApplicationVerificationFailed");
  if (iVar1 == 0) {
    return 0xfffffff3;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ArchiveDestructionFailed");
  if (iVar1 == 0) {
    return 0xfffffff2;
  }
  iVar1 = func_0x00018001cf6d(param_1,"BundleVerificationFailed");
  if (iVar1 == 0) {
    return 0xfffffff1;
  }
  iVar1 = func_0x00018001cf6d(param_1,"CarrierBundleCopyFailed");
  if (iVar1 == 0) {
    return 0xfffffff0;
  }
  iVar1 = func_0x00018001cf6d(param_1,"CarrierBundleDirectoryCreationFailed");
  if (iVar1 == 0) {
    return 0xffffffef;
  }
  iVar1 = func_0x00018001cf6d(param_1,"CarrierBundleMissingSupportedSIMs");
  if (iVar1 == 0) {
    return 0xffffffee;
  }
  iVar1 = func_0x00018001cf6d(param_1,"CommCenterNotificationFailed");
  if (iVar1 == 0) {
    return 0xffffffed;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ContainerCreationFailed");
  if (iVar1 == 0) {
    return 0xffffffec;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ContainerP0wnFailed");
  if (iVar1 == 0) {
    return 0xffffffeb;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ContainerRemovalFailed");
  if (iVar1 == 0) {
    return 0xffffffea;
  }
  iVar1 = func_0x00018001cf6d(param_1,"EmbeddedProfileInstallFailed");
  if (iVar1 == 0) {
    return 0xffffffe9;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ExecutableTwiddleFailed");
  if (iVar1 == 0) {
    return 0xffffffe8;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ExistenceCheckFailed");
  if (iVar1 == 0) {
    return 0xffffffe7;
  }
  iVar1 = func_0x00018001cf6d(param_1,"InstallMapUpdateFailed");
  if (iVar1 == 0) {
    return 0xffffffe6;
  }
  iVar1 = func_0x00018001cf6d(param_1,"ManifestCaptureFailed");
  if (iVar1 == 0) {
    return 0xffffffe5;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MapGenerationFailed");
  if (iVar1 == 0) {
    return 0xffffffe4;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingBundleExecutable");
  if (iVar1 == 0) {
    return 0xffffffe3;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingBundleIdentifier");
  if (iVar1 == 0) {
    return 0xffffffe2;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingBundlePath");
  if (iVar1 == 0) {
    return 0xffffffe1;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingContainer");
  if (iVar1 == 0) {
    return 0xffffffe0;
  }
  iVar1 = func_0x00018001cf6d(param_1,"NotificationFailed");
  if (iVar1 == 0) {
    return 0xffffffdf;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PackageExtractionFailed");
  if (iVar1 == 0) {
    return 0xffffffde;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PackageInspectionFailed");
  if (iVar1 == 0) {
    return 0xffffffdd;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PackageMoveFailed");
  if (iVar1 == 0) {
    return 0xffffffdc;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PathConversionFailed");
  if (iVar1 == 0) {
    return 0xffffffdb;
  }
  iVar1 = func_0x00018001cf6d(param_1,"RestoreContainerFailed");
  if (iVar1 == 0) {
    return 0xffffffda;
  }
  iVar1 = func_0x00018001cf6d(param_1,"SeatbeltProfileRemovalFailed");
  if (iVar1 == 0) {
    return 0xffffffd9;
  }
  iVar1 = func_0x00018001cf6d(param_1,"StageCreationFailed");
  if (iVar1 == 0) {
    return 0xffffffd8;
  }
  iVar1 = func_0x00018001cf6d(param_1,"SymlinkFailed");
  if (iVar1 == 0) {
    return 0xffffffd7;
  }
  iVar1 = func_0x00018001cf6d(param_1,"UnknownCommand");
  if (iVar1 == 0) {
    return 0xffffffd6;
  }
  iVar1 = func_0x00018001cf6d(param_1,"iTunesArtworkCaptureFailed");
  if (iVar1 == 0) {
    return 0xffffffd5;
  }
  iVar1 = func_0x00018001cf6d(param_1,"iTunesMetadataCaptureFailed");
  if (iVar1 == 0) {
    return 0xffffffd4;
  }
  iVar1 = func_0x00018001cf6d(param_1,"DeviceOSVersionTooLow");
  if (iVar1 == 0) {
    return 0xffffffd3;
  }
  iVar1 = func_0x00018001cf6d(param_1,"DeviceFamilyNotSupported");
  if (iVar1 == 0) {
    return 0xffffffd2;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PackagePatchFailed");
  if (iVar1 == 0) {
    return 0xffffffd1;
  }
  iVar1 = func_0x00018001cf6d(param_1,"IncorrectArchitecture");
  if (iVar1 == 0) {
    return 0xffffffd0;
  }
  iVar1 = func_0x00018001cf6d(param_1,"PluginCopyFailed");
  if (iVar1 == 0) {
    return 0xffffffcf;
  }
  iVar1 = func_0x00018001cf6d(param_1,"BreadcrumbFailed");
  if (iVar1 == 0) {
    return 0xffffffce;
  }
  iVar1 = func_0x00018001cf6d(param_1,"BreadcrumbUnlockFailed");
  if (iVar1 == 0) {
    return 0xffffffcd;
  }
  iVar1 = func_0x00018001cf6d(param_1,"GeoJSONCaptureFailed");
  if (iVar1 == 0) {
    return 0xffffffcc;
  }
  iVar1 = func_0x00018001cf6d(param_1,"NewsstandArtworkCaptureFailed");
  if (iVar1 == 0) {
    return 0xffffffcb;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingCommand");
  if (iVar1 == 0) {
    return 0xffffffca;
  }
  iVar1 = func_0x00018001cf6d(param_1,"NotEntitled");
  if (iVar1 == 0) {
    return 0xffffffc9;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingPackagePath");
  if (iVar1 == 0) {
    return 0xffffffc8;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingContainerPath");
  if (iVar1 == 0) {
    return 0xffffffc7;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingApplicationIdentifier");
  if (iVar1 == 0) {
    return 0xffffffc6;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingAttributeValue");
  if (iVar1 == 0) {
    return 0xffffffc5;
  }
  iVar1 = func_0x00018001cf6d(param_1,"LookupFailed");
  if (iVar1 == 0) {
    return 0xffffffc4;
  }
  iVar1 = func_0x00018001cf6d(param_1,"DictCreationFailed");
  if (iVar1 == 0) {
    return 0xffffffc3;
  }
  iVar1 = func_0x00018001cf6d(param_1,"InstallProhibited");
  if (iVar1 == 0) {
    return 0xffffffc2;
  }
  iVar1 = func_0x00018001cf6d(param_1,"UninstallProhibited");
  if (iVar1 == 0) {
    return 0xffffffc1;
  }
  iVar1 = func_0x00018001cf6d(param_1,"MissingBundleVersion");
  uVar2 = 0xffffff00;
  if (iVar1 == 0) {
    uVar2 = 0xffffffc0;
  }
  return uVar2;
}

