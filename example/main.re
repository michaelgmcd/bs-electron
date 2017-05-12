[@@@bs.config {no_export: no_export}];

external format : 'a => string = "" [@@bs.module "url"];

external platform : string = "" [@@bs.module "process"];

external join : string => string => string = "" [@@bs.module "path"];

external app : App.t = "app" [@@bs.module "electron"];

let mainWindow: ref (option BrowserWindow.instance) = ref None;

let createWindow () => {
  let dirname =
    switch [%bs.node __dirname] {
    | Some d => d
    | None => ""
    };
  let url =
    format {"pathname": join dirname "index.html", "protocol": "file:", "slashes": Js.true_};
  mainWindow := Some (BrowserWindow.make {"width": 800, "height": 600});
  switch !mainWindow {
  | Some window =>
    BrowserWindow.loadURL window url;
    BrowserWindow.on window "closed" (fun () => mainWindow := None)
  | None => ()
  }
};

let closeWindow () =>
  if (platform !== "darwin") {
    App.quit app
  };

let activate () =>
  switch !mainWindow {
  | Some _ => ()
  | None =>
    createWindow ();
    ()
  };

App.on app "ready" createWindow;

App.on app "window-all-closed" closeWindow;

App.on app "activate" activate;
