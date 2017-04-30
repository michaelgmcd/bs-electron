external gS : string => (unit => unit) => unit = "globalShortcut" [@@bs.module "electron"];

let globalShortcut = gS;

type userInfo;

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

type jumpListItemArray = array jumpListItem;

type jumpListCategory = {
  name: option string,
  items: option jumpListItemArray,
  /* Can be tasks | frequent | recent | custom (how do we type this?) */
  type_: option string
};

type jumpListCategoryArray = array jumpListCategory;

type rectangleObject = {x: int, y: int, width: int, height: int};

type sizeObject = {height: int, width: int};

type taskObject = {
  program: string,
  arguments: string,
  title: string,
  description: string,
  iconPath: string,
  iconIndex: int
};

type createFromBufferOptions = {width: option int, height: option int, scaleFactor: option float};

type optionalCreateFromBufferOptions = option createFromBufferOptions;

type buffer =
  | Node_buffer;

/* type null = Js_null; */
type nativeImageMethodOptions = {scaleFactor: option float};

type addRepresentationOptions = {
  scaleFactor: int,
  width: option int,
  height: option int,
  buffer: option buffer,
  dataURL: option string
};

/* resizeQuality is actually good | better | best (how do we type this?) */
type resizeQuality = string;

type resizeOptions = {width: option int, height: option int, quality: option resizeQuality};

type nativeImageClass = {
  addRepresentation: addRepresentationOptions => unit,
  crop: rect::rectangleObject => nativeImageClass,
  getBitmap: options::option nativeImageMethodOptions => buffer,
  getAspectRatio: unit => float,
  getNativeHandle: unit => buffer,
  getSize: unit => sizeObject,
  resize: resizeOptions => nativeImageClass,
  setTemplateImage: option::bool => unit,
  isEmpty: unit => bool,
  isTemplateImage: unit => bool,
  toBitmap: options::option nativeImageMethodOptions => buffer,
  toDataURL: options::option nativeImageMethodOptions => string,
  toJPEG: int => buffer,
  toPNG: options::option nativeImageMethodOptions => buffer
};

type nativeImage = {
  createFromDataURL: dataURL::string => nativeImageClass,
  createEmpty: unit => unit,
  createFromPath: path::string => nativeImageClass,
  createFromBuffer: buffer::buffer => options::optionalCreateFromBufferOptions => nativeImageClass
};

type getFilePathOptions = {size: string};

type arrString = array string;

type jumpListSettings = {minItems: int, removedItems: array jumpListItem};

type relaunchOptions = {args: option arrString, execPath: option string};

type defaultProtocolClientHandler =
  protocol::string => string::option string => args::option arrString => bool;

type app = {
  addRecentDocument: path::string => unit,
  clearRecentDocuments: unit => unit,
  exit: exitCode::option int => unit,
  focus: unit => unit,
  getAppPath: unit => string,
  getCurrentActivityType: unit => string,
  getFileIcon:
    path::string =>
    options::option getFilePathOptions =>
    callback::(err::exn => nativeImage::nativeImageClass => unit) =>
    unit,
  getJumpListSettings: unit => jumpListSettings,
  getLocale: unit => string,
  getName: unit => string,
  getPath: string => string,
  getVersion: unit => string,
  hide: unit => unit,
  isReady: bool => unit,
  isDefaultProtocolClient: defaultProtocolClientHandler,
  makeSingleInstance: callback::(argv::array string => workingDirectory::string => unit) => bool,
  quit: unit => unit,
  relaunch: option relaunchOptions => unit,
  releaseSingleInstance: unit => unit,
  removeAsDefaultProtocolClient: defaultProtocolClientHandler,
  setAsDefaultProtocolClient: defaultProtocolClientHandler,
  /* One of ok | error | invalidSeparatorError | fileTypeRegistrationError | customCategoryAccessDeniedError */
  setJumpList: categories::option jumpListCategoryArray => string,
  setName: name::string => unit,
  setPath: name::string => path::string => unit,
  setUserActivity: type::string => userInfo::userInfo => webpageURL::option string => unit,
  setUserTasks: tasks::array taskObject => bool,
  show: unit => unit
};

external app : app = "app" [@@bs.module "electron"];

let app = app;
