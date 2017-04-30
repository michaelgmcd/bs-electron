/* type t; */
/* type event; */
/* type certificate; */
/* type webContents; */
/* type browserWindow; */
/* type request = {method: string, url: string, referrer: string}; */
/* type authInfo = {isProxy: bool, scheme: string, host: string, port: int, realm: string}; */
/* external appOn : */
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
