/* type event; */
/* type certificate; */
/* type webContents; */
/* type browserWindow; */
/* type request = {method: string, url: string, referrer: string}; */
/* type authInfo = {isProxy: bool, scheme: string, host: string, port: int, realm: string}; */
/* external _on : */
/*   t => */
/*   [ */
/*     | `windowAllClosed ((event::unit => unit) [@bs.as "window-all-closed"]) */
/*     | `ready (launchInfo::unit => unit) */
/*     | `beforeQuit ((event::unit => unit) [@bs.as "before-quit"]) */
/*     | `willQuit ((event::unit => unit) [@bs.as "will-quit"]) */
/*     | `quit (event::string => exitCode::int => unit) */
/*     | `openFile ((event::string => path::string => unit) [@bs.as "open-file"]) */
/*     | `openUrl ((event::string => url::string => unit) [@bs.as "open-url"]) */
/*     | `activate (event::string => hasAvailableWindows::bool => unit) */
/*     | `continueActivity ( */
/*       (event::string => activityType::string => userInfo::string => unit) */
/*       [@bs.as "continue-activity"] */
/*       ) */
/*     | `browserWindowBlur ( */
/*       (event::event => window::browserWindow => unit) */
/*       [@bs.as "browser-window-blur"] */
/*       ) */
/*     | `browserWindowFocus ( */
/*       (event::event => window::browserWindow => unit) */
/*       [@bs.as "browser-window-focus"] */
/*       ) */
/*     | `browserWindowCreated ( */
/*       (event::event => window::browserWindow => unit) */
/*       [@bs.as "browser-window-created"] */
/*       ) */
/*     | `webContentsCreated ( */
/*       (event::event => webContents::webContents => unit) */
/*       [@bs.as "web-contents-created"] */
/*       ) */
/*     | `certificateError ( */
/*       ( */
/*         event::event => */
/*         webContents::webContents => */
/*         url::string => */
/*         error::string => */
/*         certificate::certificate => */
/*         callback::(isTrusted::bool => unit [@bs]) => */
/*         unit */
/*       ) */
/*       [@bs.as "certificate-error"] */
/*       ) */
/*     | `selectClientCertificate ( */
/*       ( */
/*         event::event => */
/*         webContents::webContents => */
/*         url::string => */
/*         certificateList::list certificate => */
/*         callback::(certificate::certificate => unit [@bs]) => */
/*         unit */
/*       ) */
/*       [@bs.as "select-client-certificate"] */
/*       ) */
/*     | `login ( */
/*         event::event => */
/*         webContents::webContents => */
/*         request::request => */
/*         authInfo::authInfo => */
/*         callback::(username::string => password::string => unit [@bs]) => */
/*         unit */
/*       ) */
/*     | `gpuProcessCrashed ((event::event => killed::bool => unit) [@bs.as "gpu-process-crashed"]) */
/*     | `accessibilitySupportChanged ( */
/*       (event::event => accessibilitySupportEnabled::bool => unit) */
/*       [@bs.as "accessibility-support-changed"] */
/*       ) */
/*   ] */
/*   [@bs.string] => */
/*   unit = */
/*   "on" [@@bs.send]; */
type t;

type arrString = array string;

external on : t => string => (unit => unit) => unit = "on" [@@bs.send];

external addRecentDocument : t => string => unit = "addRecentDocument" [@@bs.send];

external clearRecentDocuments : t => unit = "clearRecentDocuments" [@@bs.send];

module CommandLine = {
  type t;
  external appendSwitch : commandLine::t => switch::string => value::string? => unit =
    "appendSwitch" [@@bs.send];
  external appendArgument : t => string => unit = "appendArgument" [@@bs.send];
};

external disableHardwareAcceleration : t => unit => unit =
  "disableHardwareAcceleration" [@@bs.send];

external exit : t => exitCode::option int => unit = "exit" [@@bs.send];

external focus : t => unit => unit = "focus" [@@bs.send];

external getAppPath : t => unit => string = "getAppPath" [@@bs.send];

external getBadgeCount : t => unit => int = "getBadgeCount" [@@bs.send];

external getCurrentActivityType : t => unit => string = "getCurrentActivityType" [@@bs.send];

type getFilePathOptions = {size: string};

external getFileIcon :
  t =>
  path::string =>
  options::option getFilePathOptions =>
  callback::(err::exn => nativeImage::NativeImage.t => unit) =>
  unit =
  "getFileIcon" [@@bs.send];

type jumpListItem = {
  args: option string,
  description: option string,
  iconIndex: option string,
  iconPath: option string,
  path: option string,
  program: option string,
  title: option string,
  /* Can be task | separator | file (how do we type this?) */
  type_: option string
};

type jumpListSettings = {minItems: int, removedItems: array jumpListItem};

external getJumpListSettings : t => unit => jumpListSettings = "getJumpListSettings" [@@bs.send];

external getLocale : t => unit => string = "getLocale" [@@bs.send];

type getLoginItemSettingsOptions = {path: option string, args: option arrString};

type loginItemSettings = {
  openAtLogin: bool,
  openAsHidden: bool,
  wasOpenedAtLogin: bool,
  wasOpenedAsHidden: bool,
  restoreState: bool
};

external getLoginItemSettings :
  t => options::option getLoginItemSettingsOptions => loginItemSettings =
  "getLoginItemSettings" [@@bs.send];

external getName : t => unit => string = "getName" [@@bs.send];

external getPath : t => string => string = "getPath" [@@bs.send];

external getVersion : t => unit => string = "getVersion" [@@bs.send];

external hide : t => unit => unit = "hide" [@@bs.send];

type importCertificateOptions = {certificate: string, password: string};

external importCertificate :
  t => options::importCertificateOptions => callback::(result::int => unit) => unit =
  "importCertificate" [@@bs.send];

external isAccessibilitySupportEnabled : t => unit => bool =
  "isAccessibilitySupportEnabled" [@@bs.send];

external isReady : t => Js.boolean => unit = "isReady" [@@bs.send];

type defaultProtocolClientHandler =
  protocol::string => string::option string => args::option arrString => bool;

external isDefaultProtocolClient : t => defaultProtocolClientHandler =
  "isDefaultProtocolClient" [@@bs.send];

external setAsDefaultProtocolClient : t => defaultProtocolClientHandler =
  "setAsDefaultProtocolClient" [@@bs.send];

external removeAsDefaultProtocolClient : t => defaultProtocolClientHandler =
  "removeAsDefaultProtocolClient" [@@bs.send];

external isUnityRunning : t => unit => bool = "isUnityRunning" [@@bs.send];

external makeSingleInstance :
  t => callback::(argv::array string => workingDirectory::string => unit) => bool =
  "makeSingleInstance" [@@bs.send];

external quit : t => unit = "quit" [@@bs.send];

type relaunchOptions = {args: option arrString, execPath: option string};

external relaunch : t => option relaunchOptions => unit = "relaunch" [@@bs.send];

external releaseSingleInstance : t => unit => unit = "releaseSingleInstance" [@@bs.send];

type aboutPanelOptions = {
  applicationName: option string,
  applicationVersion: option string,
  copyright: option string,
  credits: option string,
  version: option string
};

external setAboutPanelOptions : t => options::aboutPanelOptions => unit =
  "setAboutPanelOptions" [@@bs.send];

external setAppUserModelId : t => id::string => unit = "setAppUserModelId" [@@bs.send];

external setBadgeCount : t => count::int => bool = "setBadgeCount" [@@bs.send];

type setLoginItemSettings = {openAtLogin: option bool, openAsHidden: option bool};

external setLoginItemSettings :
  t => settings::setLoginItemSettings => path::option string => args::option arrString => unit =
  "setLoginItemSettings" [@@bs.send];

type jumpListItemArray = array jumpListItem;

type jumpListCategory = {
  name: option string,
  items: option jumpListItemArray,
  /* Can be tasks | frequent | recent | custom (how do we type this?) */
  type_: option string
};

type jumpListCategoryArray = array jumpListCategory;

external setJumpList : t => categories::option jumpListCategoryArray => string =
  "setJumpList" [@@bs.send];

external setName : t => name::string => unit = "setName" [@@bs.send];

external setPath : t => name::string => path::string => unit = "setPath" [@@bs.send];

external setUserActivity : t => type::string => userInfo::'a => webpageURL::option string => unit =
  "setUserActivity" [@@bs.send];

type taskObject = {
  program: string,
  arguments: string,
  title: string,
  description: string,
  iconPath: string,
  iconIndex: int
};

external setUserTasks : t => tasks::array taskObject => bool = "setUserTasks" [@@bs.send];

external show : t => unit => unit = "show" [@@bs.send];
