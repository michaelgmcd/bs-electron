type t;

external t : t = "autoUpdater" [@@bs.module "electron"];

external checkForUpdates : t => unit => unit = "checkForUpdates" [@@bs.send];

external getFeedURL : t => unit => string = "getFeedURL" [@@bs.send];

external setFeedURL : t => url::string => requestHeaders::'a? => unit = "setFeedURL" [@@bs.send];

external quitAndInstall : t => unit => unit = "quitAndInstall" [@@bs.send];
