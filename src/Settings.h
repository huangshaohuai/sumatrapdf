// !!!!! This file is auto-generated by do/settings_gen_code.go

/* Copyright 2022 the SumatraPDF project authors (see AUTHORS file).
   License: Simplifed BSD (see COPYING) */

struct RenderedBitmap;

enum class DisplayMode {
    // automatic means: the continuous form of single page, facing or
    // book view - depending on the document's desired PageLayout
    Automatic = 0,
    SinglePage,
    Facing,
    BookView,
    Continuous,
    ContinuousFacing,
    ContinuousBookView,
};

constexpr float kZoomFitPage = -1.f;
constexpr float kZoomFitWidth = -2.f;
constexpr float kZoomFitContent = -3.f;
constexpr float kZoomActualSize = 100.0f;
constexpr float kZoomMax = 6400.f; /* max zoom in % */
constexpr float kZoomMin = 8.33f;  /* min zoom in % */
constexpr float kInvalidZoom = -99.0f;

// top, right, bottom and left margin (in that order) between window and
// document
struct WindowMargin {
    // size of the top margin between window and document
    int top;
    // size of the right margin between window and document
    int right;
    // size of the bottom margin between window and document
    int bottom;
    // size of the left margin between window and document
    int left;
};

// customization options for PDF, XPS, DjVu and PostScript UI
struct FixedPageUI {
    // color value with which black (text) will be substituted
    char* textColor;
    ParsedColor textColorParsed;
    // color value with which white (background) will be substituted
    char* backgroundColor;
    ParsedColor backgroundColorParsed;
    // color value for the text selection rectangle (also used to highlight
    // found text)
    char* selectionColor;
    ParsedColor selectionColorParsed;
    // top, right, bottom and left margin (in that order) between window
    // and document
    WindowMargin windowMargin;
    // horizontal and vertical distance between two pages in facing and
    // book view modes
    Size pageSpacing;
    // colors to use for the gradient from top to bottom (stops will be
    // inserted at regular intervals throughout the document); currently
    // only up to three colors are supported; the idea behind this
    // experimental feature is that the background might allow to
    // subconsciously determine reading progress; suggested values: #2828aa
    // #28aa28 #aa2828
    Vec<char*>* gradientColors;
    // if true, TextColor and BackgroundColor will be temporarily swapped
    bool invertColors;
    // if true, hides the scrollbars but retains ability to scroll
    bool hideScrollbars;
    // name of the font for ebook formats
    char* ebookFontName;
    // size of the font for ebook formats, 0 is default
    float ebookFontSize;
};

// customization options for Comic Book and images UI
struct ComicBookUI {
    // top, right, bottom and left margin (in that order) between window
    // and document
    WindowMargin windowMargin;
    // horizontal and vertical distance between two pages in facing and
    // book view modes
    Size pageSpacing;
    // if true, default to displaying Comic Book files in manga mode (from
    // right to left if showing 2 pages at a time)
    bool cbxMangaMode;
};

// customization options for CHM UI. If UseFixedPageUI is true,
// FixedPageUI settings apply instead
struct ChmUI {
    // if true, the UI used for PDF documents will be used for CHM
    // documents as well
    bool useFixedPageUI;
};

// list of handlers for selected text, shown in context menu when text
// selection is active. See [docs for more
// information](https://www.sumatrapdfreader.org/docs/Customize-search-translation-services)
struct SelectionHandler {
    // url to invoke for the selection. ${selection} will be replaced with
    // current selection and ${userlang} with language code for current UI
    // (e.g. 'de' for German)
    char* url;
    // name shown in context menu
    char* name;
    //
    int cmdID;
};

// list of additional external viewers for various file types. See [docs
// for more
// information](https://www.sumatrapdfreader.org/docs/Customize-external-viewers)
struct ExternalViewer {
    // command line with which to call the external viewer, may contain %p
    // for page number and "%1" for the file name (add quotation marks
    // around paths containing spaces)
    char* commandLine;
    // name of the external viewer to be shown in the menu (implied by
    // CommandLine if missing)
    char* name;
    // optional filter for which file types the menu item is to be shown;
    // separate multiple entries using ';' and don't include any spaces
    // (e.g. *.pdf;*.xps for all PDF and XPS documents)
    char* filter;
};

// these override the default settings in the Print dialog
struct PrinterDefaults {
    // default value for scaling (shrink, fit, none)
    char* printScale;
};

// customization options for how we show forward search results (used
// from LaTeX editors)
struct ForwardSearch {
    // when set to a positive value, the forward search highlight style
    // will be changed to a rectangle at the left of the page (with the
    // indicated amount of margin from the page margin)
    int highlightOffset;
    // width of the highlight rectangle (if HighlightOffset is > 0)
    int highlightWidth;
    // color used for the forward search highlight
    char* highlightColor;
    ParsedColor highlightColorParsed;
    // if true, highlight remains visible until the next mouse click
    // (instead of fading away immediately)
    bool highlightPermanent;
};

// default values for annotations in PDF documents
struct Annotations {
    // color used for highlight annotations
    char* highlightColor;
    ParsedColor highlightColorParsed;
    // color used for underline annotations
    char* underlineColor;
    ParsedColor underlineColorParsed;
    // color used for text icon annotation
    char* textIconColor;
    ParsedColor textIconColorParsed;
    // type of text annotation icon: comment, help, insert, key, new
    // paragraph, note, paragraph. If not set: note.
    char* textIconType;
    // default author for created annotations, use (none) to not add an
    // author at all. If not set will use Windows user name
    char* defaultAuthor;
};

// custom keyboard shortcuts
struct Shortcut {
    // command
    char* cmd;
    // keyboard shortcut (e.g. Ctrl-Alt-F)
    char* key;
};

// Values which are persisted for bookmarks/favorites
struct Favorite {
    // name of this favorite as shown in the menu
    char* name;
    // number of the bookmarked page
    int pageNo;
    // label for this page (only present if logical and physical page
    // numbers are not the same)
    char* pageLabel;
    // id of this favorite in the menu (assigned by AppendFavMenuItems)
    int menuId;
};

// information about opened files (in most recently used order)
struct FileState {
    // path of the document
    char* filePath;
    // Values which are persisted for bookmarks/favorites
    Vec<Favorite*>* favorites;
    // a document can be "pinned" to the Frequently Read list so that it
    // isn't displaced by recently opened documents
    bool isPinned;
    // if a document can no longer be found but we still remember valuable
    // state, it's classified as missing so that it can be hidden instead
    // of removed
    bool isMissing;
    // in order to prevent documents that haven't been opened for a while
    // but used to be opened very frequently constantly remain in top
    // positions, the openCount will be cut in half after every week, so
    // that the Frequently Read list hopefully better reflects the
    // currently relevant documents
    int openCount;
    // Hex encoded MD5 fingerprint of file content (32 chars) followed by
    // crypt key (64 chars) - only applies for PDF documents
    char* decryptionKey;
    // if true, we use global defaults when opening this file (instead of
    // the values below)
    bool useDefaultState;
    // how pages should be laid out for this document, needs to be
    // synchronized with DefaultDisplayMode after deserialization and
    // before serialization
    char* displayMode;
    // how far this document has been scrolled (in x and y direction)
    PointF scrollPos;
    // number of the last read page
    int pageNo;
    // zoom (in %) or one of those values: fit page, fit width, fit content
    char* zoom;
    // how far pages have been rotated as a multiple of 90 degrees
    int rotation;
    // state of the window. 1 is normal, 2 is maximized, 3 is fullscreen, 4
    // is minimized
    int windowState;
    // default position (can be on any monitor)
    Rect windowPos;
    // if true, we show table of contents (Bookmarks) sidebar if it's
    // present in the document
    bool showToc;
    // width of the left sidebar panel containing the table of contents
    int sidebarDx;
    // if true, the document is displayed right-to-left in facing and book
    // view modes (only used for comic book documents)
    bool displayR2L;
    // index into an ebook's HTML data from which reparsing has to happen
    // in order to restore the last viewed page (i.e. the equivalent of
    // PageNo for the ebook UI)
    int reparseIdx;
    // tocState is an array of ids for ToC items that have been toggled by
    // the user (i.e. aren't in their default expansion state). - Note: We
    // intentionally track toggle state as opposed to expansion state so
    // that we only have to save a diff instead of all states for the whole
    // tree (which can be quite large) (internal)
    Vec<int>* tocState;
    // thumbnails are saved as PNG files in sumatrapdfcache directory
    RenderedBitmap* thumbnail;
    // temporary value needed for FileHistory::cmpOpenCount
    size_t index;
};

// a subset of FileState required for restoring the state of a single
// tab (required for handling documents being opened twice)
struct TabState {
    // path of the document
    char* filePath;
    // same as FileStates -> DisplayMode
    char* displayMode;
    // number of the last read page
    int pageNo;
    // same as FileStates -> Zoom
    char* zoom;
    // same as FileStates -> Rotation
    int rotation;
    // how far this document has been scrolled (in x and y direction)
    PointF scrollPos;
    // if true, the table of contents was shown when the document was
    // closed
    bool showToc;
    // same as FileStates -> TocState
    Vec<int>* tocState;
};

// state of the last session, usage depends on RestoreSession
struct SessionData {
    // a subset of FileState required for restoring the state of a single
    // tab (required for handling documents being opened twice)
    Vec<TabState*>* tabStates;
    // index of the currently selected tab (1-based)
    int tabIndex;
    // same as FileState -> WindowState
    int windowState;
    // default position (can be on any monitor)
    Rect windowPos;
    // width of favorites/bookmarks sidebar (if shown)
    int sidebarDx;
};

// Most values on this structure can be updated through the UI and are
// persisted in SumatraPDF-settings.txt
struct GlobalPrefs {
    // customization options for PDF, XPS, DjVu and PostScript UI
    FixedPageUI fixedPageUI;
    // customization options for Comic Book and images UI
    ComicBookUI comicBookUI;
    // customization options for CHM UI. If UseFixedPageUI is true,
    // FixedPageUI settings apply instead
    ChmUI chmUI;
    // list of handlers for selected text, shown in context menu when text
    // selection is active. See [docs for more
    // information](https://www.sumatrapdfreader.org/docs/Customize-search-translation-services)
    Vec<SelectionHandler*>* selectionHandlers;
    // list of additional external viewers for various file types. See
    // [docs for more
    // information](https://www.sumatrapdfreader.org/docs/Customize-external-viewers)
    Vec<ExternalViewer*>* externalViewers;
    // zoom levels which zooming steps through in addition to Fit Page, Fit
    // Width and the minimum and maximum allowed values (8.33 and 6400)
    Vec<float>* zoomLevels;
    // zoom step size in percents relative to the current zoom level. if
    // zero or negative, the values from ZoomLevels are used instead
    float zoomIncrement;
    // these override the default settings in the Print dialog
    PrinterDefaults printerDefaults;
    // customization options for how we show forward search results (used
    // from LaTeX editors)
    ForwardSearch forwardSearch;
    // default values for annotations in PDF documents
    Annotations annotations;
    // passwords to try when opening a password protected document
    Vec<char*>* defaultPasswords;
    // if true, we remember which files we opened and their display
    // settings
    bool rememberOpenedFiles;
    // if true, we store display settings for each document separately
    // (i.e. everything after UseDefaultState in FileStates)
    bool rememberStatePerDocument;
    // if true and SessionData isn't empty, that session will be restored
    // at startup
    bool restoreSession;
    // ISO code of the current UI language
    char* uiLanguage;
    // pattern used to launch the LaTeX editor when doing inverse search
    char* inverseSearchCmdLine;
    // if true, we expose the SyncTeX inverse search command line in
    // Settings -> Options
    bool enableTeXEnhancements;
    // how pages should be laid out by default, needs to be synchronized
    // with DefaultDisplayMode after deserialization and before
    // serialization
    char* defaultDisplayMode;
    // default zoom (in %) or one of those values: fit page, fit width, fit
    // content
    char* defaultZoom;
    // custom keyboard shortcuts
    Vec<Shortcut*>* shortcuts;
    // if true, Esc key closes SumatraPDF
    bool escToExit;
    // if true, we'll always open files using existing SumatraPDF process
    bool reuseInstance;
    // if true, a document will be reloaded automatically whenever it's
    // changed (currently doesn't work for documents shown in the ebook UI)
    bool reloadModifiedDocuments;
    // background color of the non-document windows, traditionally yellow
    char* mainWindowBackground;
    ParsedColor mainWindowBackgroundParsed;
    // if true, we show the full path to a file in the title bar
    bool fullPathInTitle;
    // if false, the menu bar will be hidden for all newly opened windows
    // (use F9 to show it until the window closes or Alt to show it just
    // briefly), only applies if UseTabs is false
    bool showMenubar;
    // if true, we show the toolbar at the top of the window
    bool showToolbar;
    // if true, we show the Favorites sidebar
    bool showFavorites;
    // if true, we show table of contents (Bookmarks) sidebar if it's
    // present in the document
    bool showToc;
    // if both favorites and bookmarks parts of sidebar are visible, this
    // is the height of bookmarks (table of contents) part
    int tocDy;
    // width of favorites/bookmarks sidebar (if shown)
    int sidebarDx;
    // height of toolbar
    int toolbarSize;
    // maximum width of a single tab
    int tabWidth;
    // font size for bookmarks and favorites tree views. 0 means Windows
    // default
    int treeFontSize;
    // if true, implements smooth scrolling
    bool smoothScroll;
    // if true, we show a list of frequently read documents when no
    // document is loaded
    bool showStartPage;
    // if true, we check once a day if an update is available
    bool checkForUpdates;
    // we won't ask again to update to this version
    char* versionToSkip;
    // default state of new windows (same as the last closed)
    int windowState;
    // default position (can be on any monitor)
    Rect windowPos;
    // if true, documents are opened in tabs instead of new windows
    bool useTabs;
    // if true, we use Windows system colors for background/text color.
    // Over-rides other settings
    bool useSysColors;
    // actual resolution of the main screen in DPI (if this value isn't
    // positive, the system's UI setting is used)
    int customScreenDPI;
    // information about opened files (in most recently used order)
    Vec<FileState*>* fileStates;
    // state of the last session, usage depends on RestoreSession
    Vec<SessionData*>* sessionData;
    // a list of paths for files to be reopened at the next start or the
    // string "SessionData" if this data is saved in SessionData (needed
    // for auto-updating)
    Vec<char*>* reopenOnce;
    // timestamp of the last update check
    FILETIME timeOfLastUpdateCheck;
    // week count since 2011-01-01 needed to "age" openCount values in file
    // history
    int openCountWeek;
    // modification time of the preferences file when it was last read
    FILETIME lastPrefUpdate;
    // value of DefaultDisplayMode for internal usage
    DisplayMode defaultDisplayModeEnum;
    // value of DefaultZoom for internal usage
    float defaultZoomFloat;
};

#ifdef INCLUDE_SETTINGSSTRUCTS_METADATA

static const FieldInfo gWindowMarginFields[] = {
    {offsetof(WindowMargin, top), SettingType::Int, 2},
    {offsetof(WindowMargin, right), SettingType::Int, 4},
    {offsetof(WindowMargin, bottom), SettingType::Int, 2},
    {offsetof(WindowMargin, left), SettingType::Int, 4},
};
static const StructInfo gWindowMarginInfo = {sizeof(WindowMargin), 4, gWindowMarginFields, "Top\0Right\0Bottom\0Left"};

static const FieldInfo gSizeFields[] = {
    {offsetof(Size, dx), SettingType::Int, 4},
    {offsetof(Size, dy), SettingType::Int, 4},
};
static const StructInfo gSizeInfo = {sizeof(Size), 2, gSizeFields, "Dx\0Dy"};

static const FieldInfo gFixedPageUIFields[] = {
    {offsetof(FixedPageUI, textColor), SettingType::Color, (intptr_t) "#000000"},
    {offsetof(FixedPageUI, backgroundColor), SettingType::Color, (intptr_t) "#ffffff"},
    {offsetof(FixedPageUI, selectionColor), SettingType::Color, (intptr_t) "#f5fc0c"},
    {offsetof(FixedPageUI, windowMargin), SettingType::Compact, (intptr_t)&gWindowMarginInfo},
    {offsetof(FixedPageUI, pageSpacing), SettingType::Compact, (intptr_t)&gSizeInfo},
    {offsetof(FixedPageUI, gradientColors), SettingType::ColorArray, 0},
    {offsetof(FixedPageUI, hideScrollbars), SettingType::Bool, false},
    {offsetof(FixedPageUI, ebookFontName), SettingType::String, (intptr_t) "default"},
    {offsetof(FixedPageUI, ebookFontSize), SettingType::Float, (intptr_t) "0"},
};
static const StructInfo gFixedPageUIInfo = {sizeof(FixedPageUI), 9, gFixedPageUIFields,
                                            "TextColor\0BackgroundColor\0SelectionColor\0WindowMargin\0PageSpacing\0Gra"
                                            "dientColors\0HideScrollbars\0EbookFontName\0EbookFontSize"};

static const FieldInfo gWindowMargin_1_Fields[] = {
    {offsetof(WindowMargin, top), SettingType::Int, 0},
    {offsetof(WindowMargin, right), SettingType::Int, 0},
    {offsetof(WindowMargin, bottom), SettingType::Int, 0},
    {offsetof(WindowMargin, left), SettingType::Int, 0},
};
static const StructInfo gWindowMargin_1_Info = {sizeof(WindowMargin), 4, gWindowMargin_1_Fields,
                                                "Top\0Right\0Bottom\0Left"};

static const FieldInfo gSize_1_Fields[] = {
    {offsetof(Size, dx), SettingType::Int, 4},
    {offsetof(Size, dy), SettingType::Int, 4},
};
static const StructInfo gSize_1_Info = {sizeof(Size), 2, gSize_1_Fields, "Dx\0Dy"};

static const FieldInfo gComicBookUIFields[] = {
    {offsetof(ComicBookUI, windowMargin), SettingType::Compact, (intptr_t)&gWindowMargin_1_Info},
    {offsetof(ComicBookUI, pageSpacing), SettingType::Compact, (intptr_t)&gSize_1_Info},
    {offsetof(ComicBookUI, cbxMangaMode), SettingType::Bool, false},
};
static const StructInfo gComicBookUIInfo = {sizeof(ComicBookUI), 3, gComicBookUIFields,
                                            "WindowMargin\0PageSpacing\0CbxMangaMode"};

static const FieldInfo gChmUIFields[] = {
    {offsetof(ChmUI, useFixedPageUI), SettingType::Bool, false},
};
static const StructInfo gChmUIInfo = {sizeof(ChmUI), 1, gChmUIFields, "UseFixedPageUI"};

static const FieldInfo gSelectionHandlerFields[] = {
    {offsetof(SelectionHandler, url), SettingType::String, 0},
    {offsetof(SelectionHandler, name), SettingType::String, 0},
};
static const StructInfo gSelectionHandlerInfo = {sizeof(SelectionHandler), 2, gSelectionHandlerFields, "URL\0Name"};

static const FieldInfo gExternalViewerFields[] = {
    {offsetof(ExternalViewer, commandLine), SettingType::String, 0},
    {offsetof(ExternalViewer, name), SettingType::String, 0},
    {offsetof(ExternalViewer, filter), SettingType::String, 0},
};
static const StructInfo gExternalViewerInfo = {sizeof(ExternalViewer), 3, gExternalViewerFields,
                                               "CommandLine\0Name\0Filter"};

static const FieldInfo gPrinterDefaultsFields[] = {
    {offsetof(PrinterDefaults, printScale), SettingType::String, (intptr_t) "shrink"},
};
static const StructInfo gPrinterDefaultsInfo = {sizeof(PrinterDefaults), 1, gPrinterDefaultsFields, "PrintScale"};

static const FieldInfo gForwardSearchFields[] = {
    {offsetof(ForwardSearch, highlightOffset), SettingType::Int, 0},
    {offsetof(ForwardSearch, highlightWidth), SettingType::Int, 15},
    {offsetof(ForwardSearch, highlightColor), SettingType::Color, (intptr_t) "#6581ff"},
    {offsetof(ForwardSearch, highlightPermanent), SettingType::Bool, false},
};
static const StructInfo gForwardSearchInfo = {sizeof(ForwardSearch), 4, gForwardSearchFields,
                                              "HighlightOffset\0HighlightWidth\0HighlightColor\0HighlightPermanent"};

static const FieldInfo gAnnotationsFields[] = {
    {offsetof(Annotations, highlightColor), SettingType::Color, (intptr_t) "#ffff00"},
    {offsetof(Annotations, underlineColor), SettingType::Color, (intptr_t) "#00ff00"},
    {offsetof(Annotations, textIconColor), SettingType::Color, (intptr_t) "#ffff00"},
    {offsetof(Annotations, textIconType), SettingType::String, (intptr_t) ""},
    {offsetof(Annotations, defaultAuthor), SettingType::String, (intptr_t) ""},
};
static const StructInfo gAnnotationsInfo = {
    sizeof(Annotations), 5, gAnnotationsFields,
    "HighlightColor\0UnderlineColor\0TextIconColor\0TextIconType\0DefaultAuthor"};

static const FieldInfo gShortcutFields[] = {
    {offsetof(Shortcut, cmd), SettingType::String, (intptr_t) ""},
    {offsetof(Shortcut, key), SettingType::String, (intptr_t) ""},
};
static const StructInfo gShortcutInfo = {sizeof(Shortcut), 2, gShortcutFields, "Cmd\0Key"};

static const FieldInfo gRectFields[] = {
    {offsetof(Rect, x), SettingType::Int, 0},
    {offsetof(Rect, y), SettingType::Int, 0},
    {offsetof(Rect, dx), SettingType::Int, 0},
    {offsetof(Rect, dy), SettingType::Int, 0},
};
static const StructInfo gRectInfo = {sizeof(Rect), 4, gRectFields, "X\0Y\0Dx\0Dy"};

static const FieldInfo gFavoriteFields[] = {
    {offsetof(Favorite, name), SettingType::String, 0},
    {offsetof(Favorite, pageNo), SettingType::Int, 0},
    {offsetof(Favorite, pageLabel), SettingType::String, 0},
};
static const StructInfo gFavoriteInfo = {sizeof(Favorite), 3, gFavoriteFields, "Name\0PageNo\0PageLabel"};

static const FieldInfo gPointFFields[] = {
    {offsetof(PointF, x), SettingType::Float, (intptr_t) "0"},
    {offsetof(PointF, y), SettingType::Float, (intptr_t) "0"},
};
static const StructInfo gPointFInfo = {sizeof(PointF), 2, gPointFFields, "X\0Y"};

static const FieldInfo gRect_1_Fields[] = {
    {offsetof(Rect, x), SettingType::Int, 0},
    {offsetof(Rect, y), SettingType::Int, 0},
    {offsetof(Rect, dx), SettingType::Int, 0},
    {offsetof(Rect, dy), SettingType::Int, 0},
};
static const StructInfo gRect_1_Info = {sizeof(Rect), 4, gRect_1_Fields, "X\0Y\0Dx\0Dy"};

static const FieldInfo gFileStateFields[] = {
    {offsetof(FileState, filePath), SettingType::String, 0},
    {offsetof(FileState, favorites), SettingType::Array, (intptr_t)&gFavoriteInfo},
    {offsetof(FileState, isPinned), SettingType::Bool, false},
    {offsetof(FileState, isMissing), SettingType::Bool, false},
    {offsetof(FileState, openCount), SettingType::Int, 0},
    {offsetof(FileState, decryptionKey), SettingType::String, 0},
    {offsetof(FileState, useDefaultState), SettingType::Bool, false},
    {offsetof(FileState, displayMode), SettingType::String, (intptr_t) "automatic"},
    {offsetof(FileState, scrollPos), SettingType::Compact, (intptr_t)&gPointFInfo},
    {offsetof(FileState, pageNo), SettingType::Int, 1},
    {offsetof(FileState, zoom), SettingType::String, (intptr_t) "fit page"},
    {offsetof(FileState, rotation), SettingType::Int, 0},
    {offsetof(FileState, windowState), SettingType::Int, 0},
    {offsetof(FileState, windowPos), SettingType::Compact, (intptr_t)&gRect_1_Info},
    {offsetof(FileState, showToc), SettingType::Bool, true},
    {offsetof(FileState, sidebarDx), SettingType::Int, 0},
    {offsetof(FileState, displayR2L), SettingType::Bool, false},
    {offsetof(FileState, reparseIdx), SettingType::Int, 0},
    {offsetof(FileState, tocState), SettingType::IntArray, 0},
};
static StructInfo gFileStateInfo = {
    sizeof(FileState), 19, gFileStateFields,
    "FilePath\0Favorites\0IsPinned\0IsMissing\0OpenCount\0DecryptionKey\0UseDefaultState\0DisplayMode\0ScrollPos\0PageN"
    "o\0Zoom\0Rotation\0WindowState\0WindowPos\0ShowToc\0SidebarDx\0DisplayR2L\0ReparseIdx\0TocState"};

static const FieldInfo gPointF_1_Fields[] = {
    {offsetof(PointF, x), SettingType::Float, (intptr_t) "0"},
    {offsetof(PointF, y), SettingType::Float, (intptr_t) "0"},
};
static const StructInfo gPointF_1_Info = {sizeof(PointF), 2, gPointF_1_Fields, "X\0Y"};

static const FieldInfo gTabStateFields[] = {
    {offsetof(TabState, filePath), SettingType::String, 0},
    {offsetof(TabState, displayMode), SettingType::String, (intptr_t) "automatic"},
    {offsetof(TabState, pageNo), SettingType::Int, 1},
    {offsetof(TabState, zoom), SettingType::String, (intptr_t) "fit page"},
    {offsetof(TabState, rotation), SettingType::Int, 0},
    {offsetof(TabState, scrollPos), SettingType::Compact, (intptr_t)&gPointF_1_Info},
    {offsetof(TabState, showToc), SettingType::Bool, true},
    {offsetof(TabState, tocState), SettingType::IntArray, 0},
};
static const StructInfo gTabStateInfo = {sizeof(TabState), 8, gTabStateFields,
                                         "FilePath\0DisplayMode\0PageNo\0Zoom\0Rotation\0ScrollPos\0ShowToc\0TocState"};

static const FieldInfo gRect_2_Fields[] = {
    {offsetof(Rect, x), SettingType::Int, 0},
    {offsetof(Rect, y), SettingType::Int, 0},
    {offsetof(Rect, dx), SettingType::Int, 0},
    {offsetof(Rect, dy), SettingType::Int, 0},
};
static const StructInfo gRect_2_Info = {sizeof(Rect), 4, gRect_2_Fields, "X\0Y\0Dx\0Dy"};

static const FieldInfo gSessionDataFields[] = {
    {offsetof(SessionData, tabStates), SettingType::Array, (intptr_t)&gTabStateInfo},
    {offsetof(SessionData, tabIndex), SettingType::Int, 1},
    {offsetof(SessionData, windowState), SettingType::Int, 0},
    {offsetof(SessionData, windowPos), SettingType::Compact, (intptr_t)&gRect_2_Info},
    {offsetof(SessionData, sidebarDx), SettingType::Int, 0},
};
static const StructInfo gSessionDataInfo = {sizeof(SessionData), 5, gSessionDataFields,
                                            "TabStates\0TabIndex\0WindowState\0WindowPos\0SidebarDx"};

static const FieldInfo gFILETIMEFields[] = {
    {offsetof(FILETIME, dwHighDateTime), SettingType::Int, 0},
    {offsetof(FILETIME, dwLowDateTime), SettingType::Int, 0},
};
static const StructInfo gFILETIMEInfo = {sizeof(FILETIME), 2, gFILETIMEFields, "DwHighDateTime\0DwLowDateTime"};

static const FieldInfo gGlobalPrefsFields[] = {
    {(size_t)-1, SettingType::Comment,
     (intptr_t) "For documentation, see https://www.sumatrapdfreader.org/settings/settings3-4.html"},
    {offsetof(GlobalPrefs, fixedPageUI), SettingType::Struct, (intptr_t)&gFixedPageUIInfo},
    {offsetof(GlobalPrefs, comicBookUI), SettingType::Struct, (intptr_t)&gComicBookUIInfo},
    {offsetof(GlobalPrefs, chmUI), SettingType::Struct, (intptr_t)&gChmUIInfo},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, selectionHandlers), SettingType::Array, (intptr_t)&gSelectionHandlerInfo},
    {offsetof(GlobalPrefs, externalViewers), SettingType::Array, (intptr_t)&gExternalViewerInfo},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, zoomLevels), SettingType::FloatArray,
     (intptr_t) "8.33 12.5 18 25 33.33 50 66.67 75 100 125 150 200 300 400 600 800 1000 1200 1600 2000 2400 3200 4800 "
                "6400"},
    {offsetof(GlobalPrefs, zoomIncrement), SettingType::Float, (intptr_t) "0"},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, printerDefaults), SettingType::Struct, (intptr_t)&gPrinterDefaultsInfo},
    {offsetof(GlobalPrefs, forwardSearch), SettingType::Struct, (intptr_t)&gForwardSearchInfo},
    {offsetof(GlobalPrefs, annotations), SettingType::Struct, (intptr_t)&gAnnotationsInfo},
    {offsetof(GlobalPrefs, defaultPasswords), SettingType::StringArray, 0},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, rememberOpenedFiles), SettingType::Bool, true},
    {offsetof(GlobalPrefs, rememberStatePerDocument), SettingType::Bool, true},
    {offsetof(GlobalPrefs, restoreSession), SettingType::Bool, true},
    {offsetof(GlobalPrefs, uiLanguage), SettingType::String, 0},
    {offsetof(GlobalPrefs, inverseSearchCmdLine), SettingType::String, 0},
    {offsetof(GlobalPrefs, enableTeXEnhancements), SettingType::Bool, false},
    {offsetof(GlobalPrefs, defaultDisplayMode), SettingType::String, (intptr_t) "automatic"},
    {offsetof(GlobalPrefs, defaultZoom), SettingType::String, (intptr_t) "fit page"},
    {offsetof(GlobalPrefs, shortcuts), SettingType::Array, (intptr_t)&gShortcutInfo},
    {offsetof(GlobalPrefs, escToExit), SettingType::Bool, false},
    {offsetof(GlobalPrefs, reuseInstance), SettingType::Bool, false},
    {offsetof(GlobalPrefs, reloadModifiedDocuments), SettingType::Bool, true},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, mainWindowBackground), SettingType::Color, (intptr_t) "#80fff200"},
    {offsetof(GlobalPrefs, fullPathInTitle), SettingType::Bool, false},
    {offsetof(GlobalPrefs, showMenubar), SettingType::Bool, true},
    {offsetof(GlobalPrefs, showToolbar), SettingType::Bool, true},
    {offsetof(GlobalPrefs, showFavorites), SettingType::Bool, false},
    {offsetof(GlobalPrefs, showToc), SettingType::Bool, true},
    {offsetof(GlobalPrefs, tocDy), SettingType::Int, 0},
    {offsetof(GlobalPrefs, sidebarDx), SettingType::Int, 0},
    {offsetof(GlobalPrefs, toolbarSize), SettingType::Int, 18},
    {offsetof(GlobalPrefs, tabWidth), SettingType::Int, 300},
    {offsetof(GlobalPrefs, treeFontSize), SettingType::Int, 0},
    {offsetof(GlobalPrefs, smoothScroll), SettingType::Bool, false},
    {offsetof(GlobalPrefs, showStartPage), SettingType::Bool, true},
    {offsetof(GlobalPrefs, checkForUpdates), SettingType::Bool, true},
    {offsetof(GlobalPrefs, versionToSkip), SettingType::String, 0},
    {offsetof(GlobalPrefs, windowState), SettingType::Int, 1},
    {offsetof(GlobalPrefs, windowPos), SettingType::Compact, (intptr_t)&gRectInfo},
    {offsetof(GlobalPrefs, useTabs), SettingType::Bool, true},
    {offsetof(GlobalPrefs, useSysColors), SettingType::Bool, false},
    {offsetof(GlobalPrefs, customScreenDPI), SettingType::Int, 0},
    {(size_t)-1, SettingType::Comment, 0},
    {offsetof(GlobalPrefs, fileStates), SettingType::Array, (intptr_t)&gFileStateInfo},
    {offsetof(GlobalPrefs, sessionData), SettingType::Array, (intptr_t)&gSessionDataInfo},
    {offsetof(GlobalPrefs, reopenOnce), SettingType::StringArray, 0},
    {offsetof(GlobalPrefs, timeOfLastUpdateCheck), SettingType::Compact, (intptr_t)&gFILETIMEInfo},
    {offsetof(GlobalPrefs, openCountWeek), SettingType::Int, 0},
    {(size_t)-1, SettingType::Comment, 0},
    {(size_t)-1, SettingType::Comment, (intptr_t) "Settings below are not recognized by the current version"},
};
static const StructInfo gGlobalPrefsInfo = {
    sizeof(GlobalPrefs), 57, gGlobalPrefsFields,
    "\0FixedPageUI\0ComicBookUI\0ChmUI\0\0SelectionHandlers\0ExternalViewers\0\0ZoomLevels\0ZoomIncrement\0\0PrinterDef"
    "aults\0ForwardSearch\0Annotations\0DefaultPasswords\0\0RememberOpenedFiles\0RememberStatePerDocument\0RestoreSessi"
    "on\0UiLanguage\0InverseSearchCmdLine\0EnableTeXEnhancements\0DefaultDisplayMode\0DefaultZoom\0Shortcuts\0EscToExit"
    "\0ReuseInstance\0ReloadModifiedDocuments\0\0MainWindowBackground\0FullPathInTitle\0ShowMenubar\0ShowToolbar\0ShowF"
    "avorites\0ShowToc\0TocDy\0SidebarDx\0ToolbarSize\0TabWidth\0TreeFontSize\0SmoothScroll\0ShowStartPage\0CheckForUpd"
    "ates\0VersionToSkip\0WindowState\0WindowPos\0UseTabs\0UseSysColors\0CustomScreenDPI\0\0FileStates\0SessionData\0Re"
    "openOnce\0TimeOfLastUpdateCheck\0OpenCountWeek\0\0"};

#endif
