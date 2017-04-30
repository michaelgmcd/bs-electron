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

type nativeImageInstance = {
  addRepresentation: addRepresentationOptions => unit,
  crop: rect::rectangleObject => nativeImageInstance,
  getBitmap: options::option nativeImageMethodOptions => buffer,
  getAspectRatio: unit => float,
  getNativeHandle: unit => buffer,
  getSize: unit => sizeObject,
  resize: resizeOptions => nativeImageInstance,
  setTemplateImage: option::bool => unit,
  isEmpty: unit => bool,
  isTemplateImage: unit => bool,
  toBitmap: options::option nativeImageMethodOptions => buffer,
  toDataURL: options::option nativeImageMethodOptions => string,
  toJPEG: int => buffer,
  toPNG: options::option nativeImageMethodOptions => buffer
};

type nativeImage = {
  createFromDataURL: dataURL::string => nativeImageInstance,
  createEmpty: unit => unit,
  createFromPath: path::string => nativeImageInstance,
  createFromBuffer:
    buffer::buffer => options::optionalCreateFromBufferOptions => nativeImageInstance
};

type commandLine = {
  appendSwitch: switch::string => value::option string => unit,
  appendArgument: value::string => unit
};

/* type browserWindow = options::browserWindowOptions => browserWindowInstance; */
type browserWindowInstance = {id: int};

type menuItem;

/* Not sure what these are supposed to be */
type menuItemOptions;

type popupOptions = {
  x: option int,
  y: option int,
  async: option bool,
  positioningItem: option int
};

type menuInstance = {
  append: menuItem::menuItem => unit,
  closePopup: browserWindow::option browserWindowInstance => unit,
  insert: pos::int => menuItem::menuItem => unit,
  items: array menuItem,
  popup: browserWindow::option browserWindowInstance => options::popupOptions => unit
};

/* Can also be a string */
type icon = nativeImage;

type menu = {
  buildFromTemplate: template::array menuItemOptions => menuInstance,
  /* Can also return null */
  getApplicationMenu: unit => menuInstance,
  sendActionToFirstResponder: action::string => unit,
  /* Can also be passed null */
  setApplicationMenu: menu::menuInstance => unit
};

type dock = {
  /* One of critical | informational */
  bounce: type::option string => int,
  cancelBounce: id::int => unit,
  downloadFinished: filePath::string => unit,
  getBadge: unit => string,
  hide: unit => unit,
  isVisible: unit => bool,
  setBadge: text::string => unit,
  setIcon: image::icon => unit,
  setMenu: menu::menu => unit
};

type getFilePathOptions = {size: string};

type arrString = array string;

type jumpListSettings = {minItems: int, removedItems: array jumpListItem};

type relaunchOptions = {args: option arrString, execPath: option string};

type getLoginItemSettingsOptions = {path: option string, args: option arrString};

type setLoginItemSettings = {openAtLogin: option bool, openAsHidden: option bool};

type loginItemSettings = {
  openAtLogin: bool,
  openAsHidden: bool,
  wasOpenedAtLogin: bool,
  wasOpenedAsHidden: bool,
  restoreState: bool
};

type importCertificateOptions = {certificate: string, password: string};

type defaultProtocolClientHandler =
  protocol::string => string::option string => args::option arrString => bool;

type aboutPanelOptions = {
  applicationName: option string,
  applicationVersion: option string,
  copyright: option string,
  credits: option string,
  version: option string
};

type appType = {
  addRecentDocument: path::string => unit,
  clearRecentDocuments: unit => unit,
  commandLine,
  disableHardwareAcceleration: unit => unit,
  exit: exitCode::option int => unit,
  focus: unit => unit,
  getAppPath: unit => string,
  getBadgeCount: unit => int,
  getCurrentActivityType: unit => string,
  getFileIcon:
    path::string =>
    options::option getFilePathOptions =>
    callback::(err::exn => nativeImage::nativeImageInstance => unit) =>
    unit,
  getJumpListSettings: unit => jumpListSettings,
  getLocale: unit => string,
  getLoginItemSettings: options::option getLoginItemSettingsOptions => loginItemSettings,
  getName: unit => string,
  getPath: string => string,
  getVersion: unit => string,
  hide: unit => unit,
  importCertificate: options::importCertificateOptions => callback::(result::int => unit) => unit,
  isAccessibilitySupportEnabled: unit => bool,
  isReady: bool => unit,
  isDefaultProtocolClient: defaultProtocolClientHandler,
  isUnityRunning: unit => bool,
  makeSingleInstance: callback::(argv::array string => workingDirectory::string => unit) => bool,
  quit: unit => unit,
  relaunch: option relaunchOptions => unit,
  releaseSingleInstance: unit => unit,
  removeAsDefaultProtocolClient: defaultProtocolClientHandler,
  setAboutPanelOptions: options::aboutPanelOptions => unit,
  setAppUserModelId: id::string => unit,
  setAsDefaultProtocolClient: defaultProtocolClientHandler,
  setBadgeCount: count::int => bool,
  setLoginItemSettings:
    settings::setLoginItemSettings => path::option string => args::option arrString => unit,
  /* One of ok | error | invalidSeparatorError | fileTypeRegistrationError | customCategoryAccessDeniedError */
  setJumpList: categories::option jumpListCategoryArray => string,
  setName: name::string => unit,
  setPath: name::string => path::string => unit,
  setUserActivity: type::string => userInfo::userInfo => webpageURL::option string => unit,
  setUserTasks: tasks::array taskObject => bool,
  show: unit => unit
};

external app : appType = "app" [@@bs.module "electron"];

let app = app;

type requestHeaders;

type autoUpdaterType = {
  checkForUpdates: unit => unit,
  getFeedURL: unit => string,
  setFeedURL: url::string => requestHeaders::requestHeaders => unit,
  quitAndInstall: unit => unit
};

external autoUpdater : autoUpdaterType = "autoUpdater" [@@bs.module "electron"];

let autoUpdater = autoUpdater;
