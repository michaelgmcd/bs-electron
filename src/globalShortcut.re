type t;

external t : t = "globalShortcut" [@@bs.module "electron"];

external register : t => string => (unit => unit) => unit = "" [@@bs.send];
