type t;

type instance;

/* nativeImage */
type createFromDataURL = dataURL::string => instance;

type createEmpty = unit => unit;

type createFromPath = path::string => instance;

type createFromBufferOptions = {width: option int, height: option int, scaleFactor: option float};

type buffer =
  | Node_buffer;

type createFromBuffer = buffer::buffer => options::option createFromBufferOptions? => instance;

external instance : instance = "nativeImage" [@@bs.module "electron"];

type addRepresentationOptions = {
  scaleFactor: int,
  width: option int,
  height: option int,
  buffer: option buffer,
  dataURL: option string
};

external addRepresentation : instance => addRepresentationOptions => unit =
  "addRepresentation" [@@bs.send];

type rectangleObject = {x: int, y: int, width: int, height: int};

external crop : instance => rect::rectangleObject => instance = "crop" [@@bs.send];

type nativeImageMethodOptions = {scaleFactor: option float};

external getBitmap : instance => options::nativeImageMethodOptions? => buffer =
  "getBitmap" [@@bs.send];

external getAspectRatio : instance => unit => float = "getAspectRatio" [@@bs.send];

external getNativeHandle : instance => unit => buffer = "getNativeHandle" [@@bs.send];

type sizeObject = {height: int, width: int};

external getSize : instance => unit => sizeObject = "getSize" [@@bs.send];

/* resizeQuality is actually good | better | best (how do we type this?) */
type resizeQuality = string;

type resizeOptions = {width: option int, height: option int, quality: option resizeQuality};

external resize : instance => resizeOptions => instance = "resize" [@@bs.send];

external setTemplateImage : instance => option::Js.boolean => unit =
  "setTemplateImage" [@@bs.send];

external isEmpty : instance => unit => Js.boolean = "isEmpty" [@@bs.send];

external isTemplateImage : instance => unit => Js.boolean = "isTemplateImage" [@@bs.send];

external toBitmap : instance => options::nativeImageMethodOptions? => buffer =
  "toBitmap" [@@bs.send];

external toDataURL : instance => options::nativeImageMethodOptions? => string =
  "toDataURL" [@@bs.send];

external toJPEG : instance => int => buffer = "toJPEG" [@@bs.send];

external toPNG : instance => options::nativeImageMethodOptions? => buffer = "toPNG" [@@bs.send];
