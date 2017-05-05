type t;

type instance;

external t : t = "BrowserWindow" [@@bs.module "electron"];

external getAllWindows : t => unit => array t = "getAllWindows" [@@bs.send];

external getFocusedWindow : t => unit => option t = "getAllWindows" [@@bs.send];

external fromWebContents : t => unit => option t = "getAllWindows" [@@bs.send];

type defaultFontFamily = {
  standard: option string,
  serif: option string,
  sansSerif: option string,
  monospace: option string,
  cursive: option string,
  fantasy: option string
};

type webPreferences = {
  devTools: option bool,
  nodeIntegration: option bool,
  nodeIntegrationInWorker: option bool,
  preload: option string,
  sandbox: option bool,
  session: option Session.t,
  partition: option string,
  zoomFactor: option int,
  javascript: option bool,
  webSecurity: option bool,
  allowRunningInsecureContent: option bool,
  images: option bool,
  textAreasAreResizable: option bool,
  webgl: option bool,
  webaudio: option bool,
  plugins: option bool,
  experimentalFeatures: option bool,
  experimentalCanvasFeatures: option bool,
  scrollBounce: option bool,
  blinkFeatures: option string,
  disableBlinkFeatures: option string,
  defaultFontFamily: option defaultFontFamily,
  standard: option string,
  serif: option string,
  sansSerif: option string,
  monospace: option string,
  cursive: option string,
  fantasy: option string,
  defaultFontSize: option int,
  defaultMonospaceFontSize: option int,
  minimumFontSize: option int,
  defaultEncoding: option string,
  backgroundThrottling: option bool,
  offscreen: option bool,
  contextIsolation: option bool
};

type config = {
  width: option int,
  height: option int,
  x: option int,
  y: option int,
  useContentSize: option bool,
  center: option bool,
  minWidth: option int,
  minHeight: option int,
  maxWidth: option int,
  maxHeight: option int,
  resizable: option bool,
  movable: option bool,
  minimizable: option bool,
  maximizable: option bool,
  closable: option bool,
  focusable: option bool,
  alwaysOnTop: option bool,
  fullscreen: option bool,
  fullscreenable: option bool,
  skipTaskbar: option bool,
  kiosk: option bool,
  title: option string,
  /* TODO: This can also be a string. */
  icon: NativeImage.t,
  show: option bool,
  frame: option bool,
  parent: option t,
  modal: option bool,
  acceptFirstMouse: option bool,
  disableAutoHideCursor: option bool,
  autoHideMenuBar: option bool,
  enableLargerThanScreen: option bool,
  backgroundColor: option string,
  hasShadow: option bool,
  darkTheme: option bool,
  transparent: option bool,
  _type: option string,
  titleBarStyle: option string,
  thickFrame: option bool,
  vibrancy: option string,
  zoomToPageWidth: option bool,
  tabbingIdentifier: option string,
  webPreferences: option webPreferences
};

external make : config => instance = "BrowserWindow" [@@bs.module "electron"] [@@bs.new];
/* TODO: Add EventEmitter */
/* TODO: Finish */
