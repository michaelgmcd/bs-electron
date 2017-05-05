type t;

type instance;

external instance : instance = "webContents" [@@bs.module "electron"];

external getAllWebContents : instance => unit => array t = "" [@@bs.send];

external getFocusedWebContents : instance => unit => option t = "" [@@bs.send];

external fromId : t => int => t = "" [@@bs.send];
/* TODO: Add methods when accessed through browserWindow */
